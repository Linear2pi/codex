# Desktop AI Pet Monorepo Skeleton

本仓库现在包含可启动的项目骨架：

- `desktop/`: Tauri + React 桌宠桌面端
- `sensor-gateway/`: ESP32-S3（HLK-LD6002）传感网关固件骨架
- `host-service/`: 上位机 Python 服务骨架（串口读取 + 数据落库预留）
- `docs/`: 方案设计文档

## 快速开始

### 1) Desktop (Tauri)

```bash
cd desktop
npm install
npm run dev
```

### 2) Sensor Gateway (ESP32-S3)

- 默认按 Arduino 风格示例组织（后续可迁移 ESP-IDF）。
- 先根据实际屏幕/雷达串口修改 `sensor-gateway/firmware/src/main.cpp` 里的引脚与波特率。

### 3) Host Service

```bash
cd host-service
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
python main.py
```
使用ai完成个人桌面健康运动助手
