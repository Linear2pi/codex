# Sensor Gateway (ESP32-S3)

目标：将 HLK-LD6002 雷达与圆形触摸屏接入 ESP32-S3，并通过 USB 串口上报统一 JSON。

## 当前骨架

- `firmware/src/main.cpp`: 主循环、雷达解析、状态上报占位逻辑
- `firmware/include/protocol.h`: 与上位机通信协议字段定义

## 后续你需要做

1. 按实际屏幕驱动替换显示初始化和绘制逻辑。
2. 按 LD6002 协议完善 `parseLd6002Frame`。
3. 增加触摸事件读取并写入 telemetry。
