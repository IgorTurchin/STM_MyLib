// #########################################################################################################
// * Includes ____________________________________________________________________________________________

#include "custom.h"

// #########################################################################################################
// * Public: implementation ______________________________________________________________________________

/// **************************************************************************************
IO_t iHAL_IO_Create(GPIO_TypeDef* const port, uint16_t pin)
{
	assert_null(port);

	return (IO_t)
	{
		.port = port,
			.pin = pin,
	};
}

/// **************************************************************************************
void iHAL_IO_Config(IO_t const io, GPIO_InitTypeDef* const config)
{
	assert_null(io.port);

	config->Pin = io.pin;
	HAL_GPIO_Init(io.port, config);
}

/// **************************************************************************************
void iHAL_IO_DeConfig(IO_t const io)
{
	assert_null(io.port);

	HAL_GPIO_DeInit(io.port, io.pin);
}

/// **************************************************************************************
bool iHAL_IO_Read(IO_t const io)
{
	assert_null(io.port);

	return (io.port->IDR & io.pin) == io.pin;
}

/// **************************************************************************************
bool iHAL_IO_ReadInverse(IO_t const io)
{
	assert_null(io.port);

	return (io.port->IDR & io.pin) != io.pin;
}

/// **************************************************************************************
void iHAL_IO_Set(IO_t const io)
{
	assert_null(io.port);

	io.port->BSRR |= io.pin;
}

/// **************************************************************************************
void iHAL_IO_Reset(IO_t const io)
{
	assert_null(io.port);

	io.port->BSRR |= io.pin << 16;
}

/// **************************************************************************************
void iHAL_IO_Write(IO_t const io, bool state)
{
	assert_null(io.port);

	io.port->BSRR |= state ? io.pin : io.pin << 16;
}

/// **************************************************************************************
void iHAL_IO_Toogle(IO_t const io)
{
	assert_null(io.port);

	io.port->ODR ^= io.pin;
}

/// #########################################################################################################
/// * End file io.c                                                                                   #####
/// #####################################################################################################
