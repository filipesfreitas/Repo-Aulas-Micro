var libraries = {
    "libraries": [
        {
            "id": "driverlib",
            "arch": "msp430",
            "title": "Driver Library",
            "filter": "driverlib",
            "description": "Full API for selected MSP430 and MSP432 device families for configuring, enabling & using integrated peripherals. Each API function is fully documented through a User’s Guide, API Guide & code examples. Fly high above bitwise programming and become an MCU expert within minutes with Driver Library.<br><br>Get to market faster with Driver Library. Easy-to-understand function calls means less time learning and more time innovating. Driver Library is also relased standalone from MSPWare as a BSD software library.",
            "buttons": [
                {
                    "text": "MSP430 DriverLib",
                    "link": "http://www.ti.com/tool/msp430driverlib"
                },
                {
                    "text": "MSP432 DriverLib",
                    "link": "http://www.ti.com/tool/msp432driverlib"
                }
            ]
        },
        {
            "id": "grlib",
            "arch": "both",
            "title": "Graphics Library",
            "filter": "grlib",
            "description": "Graphics library offers an easy to use API for rapid development with any LCD paired with MSP430 or MSP432. The consistency across Graphics Library allows the same application code to be used across all LCD types. Graphics Library is powerful enough to run a QVGA while taking advantage of low power heritage.<br><br>The package includes an image reformer tool to generate code to resemble images.",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/msp430-grlib"
                }
            ]
        },
        {
            "id": "usblib430",
            "arch": "msp430",
            "title": "USB Developers Package",
            "filter": "usb developers package",
            "description": "The USB Developers Package for MSP430 is a software package containing all necessary source code and sample applications required for developing a USB-based MSP430 project. The package only supports MSP430 devices with integrated USB.<br><br>The developer's package contains a code generation tool that quickly configures the USB API stack for any combination of USB interfaces (single or composite), including descriptor generation – simply run the Tool and begin writing applications. It saves the developer's time and reduces the chance for errors.",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/msp430usbdevpack"
                }
            ]
        },
        {
            "id": "fram_utilities",
            "arch": "msp430",
            "title": "FRAM Utilities",
            "filter": "framutilities",
            "description": "The Texas Instruments FRAM Utilities is a collection of embedded software utilities that leverage the ultra-low power and virtually unlimited write endurance of FRAM. The utilities are available for MSP430FRx FRAM microcontrollers and provide example code to help start application development.<br><br>Compute Through Power Loss is a utility API set that enables ease of use with LPMx.5 lowpower modes and a powerful shutdown mode that allows an application to save and restore critical system components when a power loss is detected.",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/msp-fram-utilities"
                }
            ]
        },
        {
            "id": "iqmathlib",
            "arch": "both",
            "title": "IQ Math Library",
            "filter": "iqmath",
            "description" : "The Texas Instruments IQmath and Qmath Libraries are a collection of highly optimized and high-precision mathematical functions for C programmers to seamlessly port a floating-point algorithm into fixed-point code on MSP430 and MSP432 devices. These routines are typically used in computationally intensive real-time applications where optimal execution speed, high accuracy and ultra low energy are critical. By using the IQmath and Qmath libraries, it is possible to achieve execution speeds considerably faster and energy consumption considerably lower than equivalent code written using floating-point math.",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/iqmathlib"
                }
            ]
        },
        {
            "id": "dsplib",
            "arch": "msp430",
            "title": "Digital Signal Processing (DSP) Library for MSP MCUs",
            "filter": "dsplib",
            "description": "The Texas Instruments &reg; Digital Signal Processing library is a set of highly optimized functions to perform many common signal processing operations on fixed-point numbers for MSP430 &trade; microcontrollers. This function set is typically utilized for applications where processing-intensive transforms are done in real-time for minimal energy and with very high accuracy. This library's optimal utilization of the MSP families' intrinsic hardware for fixed-point math allows for significant performance gains.",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/msp-dsplib"
                }
            ]
        },
        {
            "id": "captouchlib",
            "arch": "both",
            "title": "Capactive Touch Software Library",
            "filter": "captouch",
            "description": "<p>Texas Instruments supports two methods for capacitive touch sensing. If starting a new design, we recommend using <a href='http://www.ti.com/captivate'>MSP MCUs featuring CapTIvate™ technology.</a></p><p>If you have already selected an MSP microcontroller, you can determine which method it uses (or if it supported at all) by referring to your device’s datasheet or the <a href='http://www.ti.com/lsds/ti/microcontrollers_16-bit_32-bit/msp/products.page'>MSP product selector</a> guide.</p><p><b>CapTIvate Technology</b> is found on TI’s MSP430FR25xx/26xx devices. These devices provide superior sensing and noise immunity, compared to TI’s previous capacitive touch implementations. Please refer to these links for more information about devices and tools featuring CapTIvate technology.</p><ul><li><a href=''>CapTIvate Design Center and Software Library</a> (MSPWare)</li><li><a href=''>CapTIvate touch microcontroller</a></li></ul><p><b>Capacitive Touch I/O</b> - most MSP microcontrollers (outside of the CapTIvate devices) support an older capacitive touch technology, often referred to as PinOsc, which includes a number of touch implementations such as the RO and RC methods.</p><p>This section of MSPWare contains the library, GUI tools, and examples supporting these methods. In addition, look to the hardware design considerations which you can use as a simple guide for including capacitive touch into any MSP-based application.</p><p>To begin with the older “Capacitive Touch I/O” we recommend you start by reading:</p><ul><li>The software <a href='http://dev.ti.com/tirex/#/?link=MSPWare%2FLibraries%2FCapacitive%20Touch%20Software%20Library%2FUser's%20Guide'>User Guide</a>:  Capacitive Touch Software Library Programmers Guide</li><li>Additionally, you might find the <a href='http://software-dl.ti.com/trainingTTO/trainingTTO_public_sw/MSP430_LaunchPad_Workshop/v2.20/MSP430_10_Capacitive_Touch.pdf'>Capacitive Touch</a> chapter from the <a href='http://processors.wiki.ti.com/index.php/Getting_Started_with_the_MSP430G2553_Value-Line_LaunchPad_Workshop'>Value-Line LaunchPad Workshop</a> a useful resource.</li></ul>",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/capsenselibrary"
                }
            ]
        },
        {
            "id": "captivate",
            "arch": "msp430",
            "title": "CapTIvate Design Center and Software Library",
            "filter": "captivate",
            "description": "<p>Texas Instruments supports two methods for capacitive touch sensing. If starting a new design, we recommend using MSP MCUs featuring CapTIvate Technology.</p><p>If you have already selected an MSP microcontroller, you can determine which method it uses (or if it supported at all) by referring to your device’s datasheet or the <a href='http://www.ti.com/lsds/ti/microcontrollers_16-bit_32-bit/msp/products.page'>MSP product selector</a> guide.</p><p><b>Capacitive Touch I/O</b> - most MSP microcontrollers (outside of the CapTIvate devices) support an older capacitive touch technology, often referred to as PinOsc, which includes touch sensing implementations such as the RO and RC methods. This allows you to add simple touch sensing to a system, even when your selected MSP microcontroller does not support CapTIvate technology. (Though, in this case, many designers choose to add an additional CapTIvate technology-capable controller to get access to its superior capacitive sensing benefits and features.)</p><p><b>CapTIvate Technology</b> - found on TI’s MSP430FR25xx/26xx devices. These devices provide superior sensing and noise immunity, compared TI’s previous capacitive touch implementations. Please refer to these links for more information about CapTIvate Technology, devices and tools.</p><h4>Getting Started with CapTIvate Technology</h4><h5>STEP 1: Purchase the CapTIvate Kit</h5><p>Get Information about or order the CapTIvate MCU Development Kit (MSP-CAPT-FR2633) from: <a href='http://www.ti.com/msp-capt-fr2633'>http://www.ti.com/msp-capt-fr2633</a></p><h5>Install CapTIvate Design Center</h5><p>Available as part of MSPWare: <a href='http://www.ti.com/tool/mspware'>http://www.ti.com/tool/mspware</a> or as a separate download: <a href='http://www.ti.com/captivatedesigncenter'>http://www.ti.com/captivatedesigncenter</a></p><h5>STEP 3: Install and update your IDE - Code Composer Studio™ or IAR Embedded Workbench</h5><p><b>IMPORTANT</b>: Please update your IDE with the latest device and emulation support for MSP430FR2633.</p><h5>STEP 4: Getting Started with CapTIvate Out-of-box Experience Demo Wake-on-Proximity</h5><p>Get started with the Out-of-Box demo documented in the <a href='http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/CapTIvate_Design_Center/latest/exports/docs/users_guide/html/ch_workshop.html'>CapTIvate™ Technology Guide.</a></p><h5>STEP 5: CapTIvate Hands-on Workshop</h5><p>Following the Out-of-Box demo, you will find a series of hands-on lab exercises to introduce you to the software and tools that will help you to make the most of CapTIvate. Please find the exercises in the <a href='http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/CapTIvate_Design_Center/latest/exports/docs/users_guide/html/ch_workshop.html'>CapTIvate™ Technology Guide.</a></p><h5>STEP 6: Invent Something New</h5><p>Now that you have spent time exploring, implementing, and tuning using the CapTIvate Design Center, try creating a project of your own. As you have seen, when following the Hands-on Exercises in the previous step, you should always start a new CapTIvate project using the CapTIvate Design Center. Once again, here are the basic steps:<ul><li>Create a new project using the CapTIvate Design Center</li><li>Use the design center to describe your sense elements (buttons, sliders, wheel, and proximity). Then allow the GUI to generate an IDE project – along with code – specific to the Integrated Development Environment (IDE) that you will be using to compile and build your application (e.g. CCS, IAR).</li><li>Open the new project in the IDE you are using to compile and download the firmware to the CapTIvate microcontroller.</li><li>With the application running on your CapTIvate microcontroller, switch back to CapTIvate Design Center to begin tuning your capacitive elements.</li></ul></p>",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/captivate"
                }
            ]
        },
        {
            "id": "iec60730",
            "arch": "msp430",
            "title": "IEC60730 Development Library",
            "filter": "iec60730",
            "description": "IEC60730 library offers a complete set of API calls that allow users to perform self-test routines on MSP430 devices. The tests meet the Class B requirements specified in the software section of Annex H of the IEC60730 standard.<br><br>The development library contains an easy-to-use GUI tool to quickly generate custom configuraiton header files to use in your IEC60730 project.",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/msp430-iec60730-sw-package"
                }
            ]
        },
        {
            "id": "smbuslib",
            "arch": "msp430",
            "title": "SMBusLib",
            "filter": "smbuslib",
            "description": "<p>The System Management Bus (abbreviated to SMBus)  is a single-ended simple two-wire bus for the purpose of lightweight communication. Most commonly it is found in computer motherboards for communication with the power source for ON/OFF instructions.</p><br><p>The MSP430 SMBUS Library is a royalty-free set of primitives for enabling communication with external devices supporting SMBus like battery chargers, sensors etc. The library is implemented in both Master as well as Slave modes and supported on a wide range of MSP430 devices including the MSP430 Value Line devices as well as FRAM devices.</p>",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/MSP430-SMBUS"
                }
            ]
        },
        {
            "id": "pmbuslib",
            "arch": "msp430",
            "title": "PMBusLib",
            "filter": "pmbuslib",
            "description": "The MSP Power Management Bus (PMBus) Embedded Software Library is a free C library for enabling PMBus master implementation on MSP microcontrollers that have our eUSCI/USCI serial communication peripheral. In addition, the library has supports for additional features:<br><ul><li>Alert response (for host notification in the presence of fault)</li><li>Control line (for turning the slave device on/off).</li><li>Packet Error Checking (PEC)</li></ul><br>The PMBus specification is an industry-wide standard that can be viewed as a step toward unifying communication standards for power conversion and digital power-management devices. It was developed by the PMBus Implementers Forum (PMBus-IF). The standard uses the widely accepted Inter-Integrated Circuit (I2C) communication protocol for the hardware interface. A number of additional features serve to enhance the basic I2C communication protocol. The PMBus standard is also considered to be an extension to the System Management Bus (SMBus) protocol that was popularized by the SBS Implementers Forum for battery systems.",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/MSP-PMBus"
                }
            ]
        },
        {
            "id": "speech_recognizer",
            "arch": "msp432",
            "title": "Speech Recognizer Library",
            "filter": "speechlibrary",
            "description": "The Speech Recognizer Library implements a fixed-point speaker-dependent speech recognizer targeted toward embedded processors. The library provides easy-to-use APIs that can voice enable applications. Resources in addition to the library include an example project illustrating the use of MinHMM.<br><br>Prior to using a speaker-dependent speech recognizer, the user must train the recognizer with each phrase to recognize by speaking the phrase several times. During training, the recognizer creates a model of each phrase to use during the recognition process. The performance of the recognizer is thus tied to the speaker that trained each phrase. If another speaker tries to use the recognizer, performance will likely degrade due to differences in the way the phrase is spoken.",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/msp-speech-recognizer"
                }
            ]
        },
        {
            "id": "nfclink",
            "arch": "msp430",
            "title": "NFCLink NFC and HF RFID Firmware",
            "filter": "nfclink",
            "description": "NFCLink is a library of NFC & HF RFID firmware using the NCI protocol to communicate to a host OS or MPU. As of today, NFCLink supports MSP4305xx_6xx series devices.<br><br>Features<ul><li>Supports NFC/HF RFID Reader/Writer functions for formatting, reading and writing</li><li>NFC Tag Type Platforms 2, 3, 4A, 4B and V (ISO15693).</li><li>Supports NFC/HF Peer to Peer functions (Initiator and Target) using SNEP and NPP</li><li>Supports Card Emulation functions as NFC Tag Type Platforms 4A & 4B</li><li>Windows XP/7 based GUI with integrated stack (for use with MSP-EXP430F5529 + TRF7970ATB hardware platform)</li></ul>",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/nfclink?DCMP=nfc-rf430cl&HQS=nfclink"
                }
            ]
        },
        {
            "id": "energy",
            "arch": "msp430",
            "title": "Energy Library",
            "description": "The MSP430 Energy Library is a software suite designed for quick ramp-up in metering, smart grid, energy monitoring and home/building automation applications where precise measurements are key criteria. This library provides easy-to-use code for developers who need to perform standard tasks without needing to know all the details behind each peripheral of the MCU.<br><br>CCS port not yet available, click link below for IAR package.",
            "buttons": [
                {
                    "text": "Learn More",
                    "link": "http://www.ti.com/tool/msp430-energy-library"
                }
            ]
        }
    ]
}
