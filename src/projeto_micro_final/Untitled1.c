  
 //*****************************************************************************
//
//! Initializes the I2C Master block.
//!
//!
//! This function initializes operation of the I2C Master block.  Upon
//! successful initialization of the I2C block, this function will have set the
//! bus speed for the master; however I2C module is still disabled till
//! I2C_enable is invoked
//!
//!
//! Modified bits are \b UCMST,UCMODE_3,\b UCSYNC of \b UCBxCTL0 register
//!                   \b UCSSELx, \b UCSWRST, of \b UCBxCTL1 register
//!                   \b UCBxBR0 and \b UCBxBR1 regsiters
//! \return None.
//
//*****************************************************************************
 
  I2C_masterInit();
 
  //*****************************************************************************
//
//! Disables the I2C block.
//!
//! \param baseAddress is the base address of the USCI I2C module.
//!
//! This will disable operation of the I2C block.
//! Modified bits are \b UCSWRST of \b UCBxCTL1 register.
//!
//! \return None.
//
//*****************************************************************************

  I2C_disable ();
  
  
//*****************************************************************************
//
//! Sets the address that the I2C Master will place on the bus.
//!
//! \param slaveAddress 7-bit slave address
//!
//! This function will set the address that the I2C Master will place on the
//! bus when initiating a transaction.
//! Modified bits are \b UCSWRST of \b UCBxCTL1 register
//!                   \b UCBxI2CSA register
//!
//! \return None.
//
//*****************************************************************************

  I2C_setSlaveAddress (unsigned char slaveAddress);
  
//*****************************************************************************
//
//! Sets the mode of the I2C device
//!
//! \param receive indicates whether module is in transmit/receive mode
//!
//! When the receive parameter is set to I2C_TRANSMIT_MODE, the address will
//! indicate that the I2C module is in receive mode; otherwise, the I2C module
//! is in send mode. Valid values are
//!     \b I2C_TRANSMIT_MODE
//!     \b I2C_RECEIVE_MODE [Default value]
//! Modified bits are \b UCTR of \b UCBxCTL1 register
//!
//! \return None.
//
//*****************************************************************************
  I2C_setMode ( unsigned char mode );

  
//*****************************************************************************
//
//! Enables the I2C block.
//!
//! \param baseAddress is the base address of the USCI I2C module.
//!
//! This will enable operation of the I2C block.
//! Modified bits are \b UCSWRST of \b UCBxCTL1 register.
//!
//! \return None.
//
//*****************************************************************************
  I2C_enable ();
  
