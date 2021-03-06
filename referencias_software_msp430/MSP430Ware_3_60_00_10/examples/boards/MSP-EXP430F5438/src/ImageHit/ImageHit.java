/*******************************************************************************
 *
 *  ImageHit.java - A command line image converter to create C data structures
 *                  that can be efficiently processed by HD66753-based LCDs.
 *
 *  Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

import java.awt.image.BufferedImage;
import java.io.*;
import javax.imageio.ImageIO;

/**
 * @author	Andreas Dannenberg, Texas Instruments, Inc.
 * @version	1.0
 */
public class ImageHit {
	/**
	 * Shows the command line usage help and exits the program.
	 */
	static void showUsageAndExit() {
		System.err.println("ImageHit V1.0 - A command line image converter to create C data structures");
		System.err.println("that can be efficiently processed by HD66753-based displays.");
		System.err.println();
		System.err.println("Program by Andreas Dannenberg");
		System.err.println("(C)2011 Texas Instruments, Inc.");
		System.err.println();
		System.err.println("Usage: ImageHit [-v] file");
		System.err.println("  file   Input image file in either JPEG, PNG, BMP, or GIF format.");
		System.err.println("  -v     Cause ImageHit to be verbose, showing various image stats");
		System.err.println("         and rendering the actual monochrome image to the console.");		
		System.exit(1);		
	}
	
	/**
	 * Function reads out a pixel from a BufferedImage object and returns a converted 2-bit
	 * gray scale value. In case the pixel that is read is located outside the actual image,
	 * 0 is returned.
	 * 
	 * @param	image	A BufferedImage object
	 * @param	x		Horizontal pixel coordinate
	 * @param	y		Vertical pixel coordinate
	 * @return			2-bit gray scale pixel value (0 to 3, with 3 being the darkest)
	 * @see				BufferedImage
	 */	
	static int getPixel(BufferedImage image, int x, int y) {
		final int darkGrayThreshold = 64;
		final int mediumGrayThreshold = 128;
		final int lightGrayThreshold = 192;
		int pixel = 0;
		
		// Read pixel and split the value into the different components. Then, determine whether
		// the resulting monochrome pixel should be turned on based on a gray scale threshold.
		// Note that the alpha value contained in the MSB of the RGB value is not used.
		if ((x < image.getWidth()) && (y < image.getHeight())) {
			int rgba = image.getRGB(x, y);
			int red =   (rgba & 0x00ff0000) >>> 16;
			int green = (rgba & 0x0000ff00) >>> 8;
			int blue =   rgba & 0x000000ff;
			int gray = (red + green + blue) / 3;
			
			if (gray < darkGrayThreshold) {
				pixel = 3;
			}
			else if (gray < mediumGrayThreshold) {
				pixel = 2;
			}
			else if (gray < lightGrayThreshold) {
				pixel = 1;
			}
			else {
				pixel = 0;
			}
		}

		return pixel;
	}
	
	private static int column = 0;
	
	/**
	 * Function to output a word into a C-formatted array structure, generating the
	 * proper indentation and wrapping lines after each 16 byte that were output.
	 * 
	 * @param value		16-bit value to be output to the console
	 */	
	static void printWord(int value) {
		if (column == 0) {
			System.out.printf("    0x%04x", value);
			column++;
		}
		else if (column == 8) {
			System.out.printf(",\n    0x%04x", value);
			column = 1;
		}
		else {		
			System.out.printf(", 0x%04x", value);
			column++;
		}
	}
	
	/**
	 * This is the main entry point for starting ImageHit from the command line.
	 * 
	 * @param args		Command line arguments
	 */
	public static void main(String[] args) {
		String imagePath = "";
		Boolean verbose = false;
		
		// We expect at least one command line argument. Show help and exit otherwise.
		if (args.length == 0) {
			showUsageAndExit();
		}
		else if (args.length == 1) {
			imagePath = args[0];
		}
		else if (args.length == 2) {
			if (args[0].equals("-v")) {
				verbose = true;
				imagePath = args[1];
			}
			else {
				showUsageAndExit();
			}
		}
		else {
			showUsageAndExit();
		}
		
		// Load the image
		if (verbose) {
			System.out.println("Loading image '" + imagePath + "'...");
		}
		
		BufferedImage image = null;		
		try {
			image = ImageIO.read(new File(imagePath));
		} catch (IOException e) {
			System.err.println("Error: " + e.toString());
			return;
		}
		
		// Restrict our output image to 138x110 pixels in size and calculate the number of
		// 8-bit high rows that will be generated.
		int imageWidth = image.getWidth() > 138 ? 138 : image.getWidth();
		int imageHeight = image.getHeight() > 110 ? 110 : image.getHeight();
		int imageCols = (imageWidth + 7) / 8;		
		
		// Loading the image was successful. Now show some stats and print the actual grayscale-
		// converted image as it will be later written into the C-array.
		if (verbose) {
			System.out.println("Original image size: " + image.getWidth() + "x" + image.getHeight() + " pixels");
			System.out.println("Converted image size: " + imageWidth + "x" + imageHeight + " pixels");
			System.out.println("Converted image cols: " + imageCols); 
			System.out.println("Converted monochrome image:");

			for (int y = 0; y < imageHeight; y++) {
				for (int x = 0; x < imageWidth; x++) {
					// Convert our 2-bit gray scale value into some nice ASCII art... 
					switch (getPixel(image, x, y )) {
						case 0:
							System.out.printf("@");
							break;
						case 1:
							System.out.printf("O");
							break;
						case 2:
							System.out.printf(":");
							break;
						default:
							System.out.printf(" ");
							break;
					}
				}
				System.out.println();
			}		
		}
		
		// Generate C-array containing the monochrome image data
		System.out.printf("// This image has been created by ImageHit using '" + imagePath + "'\n");
		System.out.printf("// Image Columns: %d (1 col = 8 pixels)\n", imageCols);
		System.out.printf("// Image Rows:    %d\n", imageHeight);
		System.out.printf("const unsigned int image[] =\n");
		System.out.printf("{\n");

		for (int y = 0; y < imageHeight; y++) {
			for (int x = 0; x < imageWidth; x += 8) {
				int pixels = 0;
				for (int col = 0; col < 8; col++) {
					pixels |= getPixel(image, x + col, y) << (col << 1);
				}
				printWord(pixels);
			}		
		}		
		
		System.out.printf("\n};\n");
	}
}
