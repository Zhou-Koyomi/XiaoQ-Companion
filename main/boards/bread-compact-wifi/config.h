#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// 使用 Simplex I2S 模式（扩展板）
#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX

// ========== 扩展版音频引脚定义 ==========
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_3   // 麦克风 WS（原 GPIO4 → 改为 GPIO3）
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_9   // 麦克风 SCK（原 GPIO5 → 改为 GPIO9）
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_10  // 麦克风 SD  (原 GPIO6 → 改为 GPIO10)
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_6   // 功放 DIN  (原 GPIO7 → 改为 GPIO6)
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_5   // 功放 BCLK（原 GPIO15 → 改为 GPIO5）
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_4   // 功放 LRC  （原 GPIO16 → 改为 GPIO4）

#else
// 若使用 Duplex 模式（全双工），此处也同步改为扩展版引脚（但实际未使用）
#define AUDIO_I2S_GPIO_WS   GPIO_NUM_3
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_5
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_10
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_6
#endif

// ====== 其余外设引脚（与原来完全相同） ======
#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_47
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_40
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_39

// 显示屏（你不需要，但代码中仍保留定义，不影响运行）
#define DISPLAY_SDA_PIN GPIO_NUM_41
#define DISPLAY_SCL_PIN GPIO_NUM_42
#define DISPLAY_WIDTH   128

#if CONFIG_OLED_SSD1306_128X32
#define DISPLAY_HEIGHT  32
#elif CONFIG_OLED_SSD1306_128X64
#define DISPLAY_HEIGHT  64
#elif CONFIG_OLED_SH1106_128X64
#define DISPLAY_HEIGHT  64
#define SH1106
#else
#error "OLED display type is not selected"
#endif

#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y true

// 灯控（扩展板若有灯控，仍使用 GPIO18）
#define LAMP_GPIO GPIO_NUM_18

#endif // _BOARD_CONFIG_H_