import json
import time
from pathlib import Path

import serial

SERIAL_PORT = "/dev/ttyACM0"
BAUDRATE = 115200
OUT = Path("telemetry.log")


def main() -> None:
    print(f"[host] listening serial={SERIAL_PORT} baud={BAUDRATE}")
    with serial.Serial(SERIAL_PORT, BAUDRATE, timeout=1) as ser, OUT.open("a", encoding="utf-8") as f:
        while True:
            line = ser.readline().decode("utf-8", errors="ignore").strip()
            if not line:
                continue
            try:
                payload = json.loads(line)
            except json.JSONDecodeError:
                continue

            payload["ingested_at"] = time.time()
            row = json.dumps(payload, ensure_ascii=False)
            print(row)
            f.write(row + "\n")
            f.flush()


if __name__ == "__main__":
    main()
