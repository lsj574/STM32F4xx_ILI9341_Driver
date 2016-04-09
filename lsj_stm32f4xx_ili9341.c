/**
 *Author : 이석준 (Lee Seokjun)
 *ILI9341 LCD Driver for STM32F4xx
 *Based on Reference Library from Adafruit
 */

#include "lsj_stm32f4xx_ili9341.h"
#include <stm32f4xx_hal.h>
#include <stdint.h>

void LSJ_ILI9341_InitIO()
{
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = ILI9341_CS_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(ILI9341_CS_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = ILI9341_DC_PIN;
	HAL_GPIO_Init(ILI9341_DC_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = ILI9341_RST_PIN;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	HAL_GPIO_Init(ILI9341_RST_GPIO_PORT, &GPIO_InitStruct);
}

void LSJ_ILI9341_InitLCD()
{
	HAL_GPIO_WritePin(ILI9341_RST_GPIO_PORT, ILI9341_RST_PIN, GPIO_PIN_SET);
	HAL_Delay(5);
	HAL_GPIO_WritePin(ILI9341_RST_GPIO_PORT, ILI9341_RST_PIN, GPIO_PIN_RESET);
	HAL_Delay(20);
	HAL_GPIO_WritePin(ILI9341_RST_GPIO_PORT, ILI9341_RST_PIN, GPIO_PIN_SET);
	HAL_Delay(150);

	LSJ_ILI9341_WriteCommand(0xEF);
	LSJ_ILI9341_WriteData(0x03);
	LSJ_ILI9341_WriteData(0x80);
	LSJ_ILI9341_WriteData(0x02);

	LSJ_ILI9341_WriteCommand(0xCF);
	LSJ_ILI9341_WriteData(0x00);
	LSJ_ILI9341_WriteData(0XC1);
	LSJ_ILI9341_WriteData(0X30);

	LSJ_ILI9341_WriteCommand(0xED);
	LSJ_ILI9341_WriteData(0x64);
	LSJ_ILI9341_WriteData(0x03);
	LSJ_ILI9341_WriteData(0X12);
	LSJ_ILI9341_WriteData(0X81);

	LSJ_ILI9341_WriteCommand(0xE8);
	LSJ_ILI9341_WriteData(0x85);
	LSJ_ILI9341_WriteData(0x00);
	LSJ_ILI9341_WriteData(0x78);

	LSJ_ILI9341_WriteCommand(0xCB);
	LSJ_ILI9341_WriteData(0x39);
	LSJ_ILI9341_WriteData(0x2C);
	LSJ_ILI9341_WriteData(0x00);
	LSJ_ILI9341_WriteData(0x34);
	LSJ_ILI9341_WriteData(0x02);

	LSJ_ILI9341_WriteCommand(0xF7);
	LSJ_ILI9341_WriteData(0x20);

	LSJ_ILI9341_WriteCommand(0xEA);
	LSJ_ILI9341_WriteData(0x00);
	LSJ_ILI9341_WriteData(0x00);

	LSJ_ILI9341_WriteCommand(ILI9341_PWCTR1);    //Power control
	LSJ_ILI9341_WriteData(0x23);   //VRH[5:0]

	LSJ_ILI9341_WriteCommand(ILI9341_PWCTR2);    //Power control
	LSJ_ILI9341_WriteData(0x10);   //SAP[2:0];BT[3:0]

	LSJ_ILI9341_WriteCommand(ILI9341_VMCTR1);    //VCM control
	LSJ_ILI9341_WriteData(0x3e);
	LSJ_ILI9341_WriteData(0x28);

	LSJ_ILI9341_WriteCommand(ILI9341_VMCTR2);    //VCM control2
	LSJ_ILI9341_WriteData(0x86);  //--

	LSJ_ILI9341_WriteCommand(ILI9341_MADCTL);    // Memory Access Control
	LSJ_ILI9341_WriteData(0x48);

	LSJ_ILI9341_WriteCommand(ILI9341_PIXFMT);
	LSJ_ILI9341_WriteData(0x55);

	LSJ_ILI9341_WriteCommand(ILI9341_FRMCTR1);
	LSJ_ILI9341_WriteData(0x00);
	LSJ_ILI9341_WriteData(0x18);

	LSJ_ILI9341_WriteCommand(ILI9341_DFUNCTR);    // Display Function Control
	LSJ_ILI9341_WriteData(0x08);
	LSJ_ILI9341_WriteData(0x82);
	LSJ_ILI9341_WriteData(0x27);

	LSJ_ILI9341_WriteCommand(0xF2);    // 3Gamma Function Disable
	LSJ_ILI9341_WriteData(0x00);

	LSJ_ILI9341_WriteCommand(ILI9341_GAMMASET);    //Gamma curve selected
	LSJ_ILI9341_WriteData(0x01);

	LSJ_ILI9341_WriteCommand(ILI9341_GMCTRP1);    //Set Gamma
	LSJ_ILI9341_WriteData(0x0F);
	LSJ_ILI9341_WriteData(0x31);
	LSJ_ILI9341_WriteData(0x2B);
	LSJ_ILI9341_WriteData(0x0C);
	LSJ_ILI9341_WriteData(0x0E);
	LSJ_ILI9341_WriteData(0x08);
	LSJ_ILI9341_WriteData(0x4E);
	LSJ_ILI9341_WriteData(0xF1);
	LSJ_ILI9341_WriteData(0x37);
	LSJ_ILI9341_WriteData(0x07);
	LSJ_ILI9341_WriteData(0x10);
	LSJ_ILI9341_WriteData(0x03);
	LSJ_ILI9341_WriteData(0x0E);
	LSJ_ILI9341_WriteData(0x09);
	LSJ_ILI9341_WriteData(0x00);

	LSJ_ILI9341_WriteCommand(ILI9341_GMCTRN1);
	LSJ_ILI9341_WriteData(0x00);
	LSJ_ILI9341_WriteData(0x0E);
	LSJ_ILI9341_WriteData(0x14);
	LSJ_ILI9341_WriteData(0x03);
	LSJ_ILI9341_WriteData(0x11);
	LSJ_ILI9341_WriteData(0x07);
	LSJ_ILI9341_WriteData(0x31);
	LSJ_ILI9341_WriteData(0xC1);
	LSJ_ILI9341_WriteData(0x48);
	LSJ_ILI9341_WriteData(0x08);
	LSJ_ILI9341_WriteData(0x0F);
	LSJ_ILI9341_WriteData(0x0C);
	LSJ_ILI9341_WriteData(0x31);
	LSJ_ILI9341_WriteData(0x36);
	LSJ_ILI9341_WriteData(0x0F);
	LSJ_ILI9341_WriteCommand(ILI9341_SLPOUT);
	HAL_Delay(120);
	LSJ_ILI9341_WriteCommand(ILI9341_DISPON);
}

void LSJ_ILI9341_SetAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
	LSJ_ILI9341_WriteCommand(ILI9341_CASET); // Column addr set
	LSJ_ILI9341_WriteData(x0 >> 8);
	LSJ_ILI9341_WriteData(x0 & 0xFF);     // XSTART
	LSJ_ILI9341_WriteData(x1 >> 8);
	LSJ_ILI9341_WriteData(x1 & 0xFF);     // XEND

	LSJ_ILI9341_WriteCommand(ILI9341_PASET); // Row addr set
	LSJ_ILI9341_WriteData(y0>>8);
	LSJ_ILI9341_WriteData(y0);     // YSTART
	LSJ_ILI9341_WriteData(y1>>8);
	LSJ_ILI9341_WriteData(y1);     // YEND

	LSJ_ILI9341_WriteCommand(ILI9341_RAMWR); // write to RAM
}

void LSJ_ILI9341_DrawPixel(int16_t x, int16_t y, uint16_t color)
{
	if (x < 0 || x >= ILI9341_TFTWIDTH || y < 0 || y >= ILI9341_TFTHEIGHT)
		return;
	LSJ_ILI9341_SetAddrWindow(x, y, x+1, y+1);
	HAL_GPIO_WritePin(ILI9341_DC_GPIO_PORT, ILI9341_DC_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ILI9341_CS_GPIO_PORT, ILI9341_CS_PIN, GPIO_PIN_RESET);
	uint8_t color2 = color >> 8;
	uint8_t color1 = color;
	HAL_SPI_Transmit_DMA(&hspi2, &color2, sizeof(color2));
	HAL_SPI_Transmit_DMA(&hspi2, &color1, sizeof(color1));
	HAL_GPIO_WritePin(ILI9341_CS_GPIO_PORT, ILI9341_CS_PIN, GPIO_PIN_SET);
}

void LSJ_ILI9341_WriteCommand(uint8_t c)
{
	HAL_GPIO_WritePin(ILI9341_DC_GPIO_PORT, ILI9341_DC_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ILI9341_CS_GPIO_PORT, ILI9341_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit_DMA(&hspi2, &c, sizeof(c));
	HAL_GPIO_WritePin(ILI9341_CS_GPIO_PORT, ILI9341_CS_PIN, GPIO_PIN_SET);
}

void LSJ_ILI9341_WriteData(uint8_t c)
{
	HAL_GPIO_WritePin(ILI9341_DC_GPIO_PORT, ILI9341_DC_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ILI9341_CS_GPIO_PORT, ILI9341_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit_DMA(&hspi2, &c, sizeof(c));
	HAL_GPIO_WritePin(ILI9341_CS_GPIO_PORT, ILI9341_CS_PIN, GPIO_PIN_SET);
}

void LSJ_ILI9341_FillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
	if (x >= ILI9341_TFTWIDTH || y >= ILI9341_TFTHEIGHT)
		return;
	if (x + w -1 >= ILI9341_TFTWIDTH)
		w = ILI9341_TFTWIDTH - x;
	if (y + h - 1 >= ILI9341_TFTHEIGHT)
		h = ILI9341_TFTHEIGHT - y;
	LSJ_ILI9341_SetAddrWindow(x, y, x + w - 1, y + h - 1);
	uint8_t hi = color >> 8, lo = color;
	HAL_GPIO_WritePin(ILI9341_DC_GPIO_PORT, ILI9341_DC_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ILI9341_CS_GPIO_PORT, ILI9341_CS_PIN, GPIO_PIN_RESET);
	for (y = h; y > 0; y--)
		for (x = w; x > 0; x--)
		{
			HAL_SPI_Transmit_DMA(&hspi2, &hi, sizeof(hi));
			HAL_SPI_Transmit_DMA(&hspi2, &lo, sizeof(lo));
		}
	HAL_GPIO_WritePin(ILI9341_CS_GPIO_PORT, ILI9341_CS_PIN, GPIO_PIN_SET);
}

void LSJ_ILI9341_FillScreen(uint16_t color)
{
	LSJ_ILI9341_FillRect(0, 0, ILI9341_TFTWIDTH, ILI9341_TFTHEIGHT, color);
}
