# Smart-Energy-Meter-System
IoT Smart Energy Meter using ACS712 &amp; Arduino to monitor real-time power consumption - Task 6 Slashmark LMS
# Smart-Energy-Meter-System
**Task 6 - Slashmark LMS | ADVANCED**

## 📌 Description
IoT-based Smart Energy Meter to track and analyze real-time power consumption using ACS712 current sensor. Calculates Current, Power, and Energy kWh. Data logged via Serial Monitor for analytics.

## ⏱️ Duration: 10 hours
## 🎯 Project Complexity: Medium

## 🎓 Learning Outcome
- Power consumption monitoring using current sensors
- Real-time energy analytics and data visualization
- kWh calculation and utility billing logic
- Serial data logging for storage

## 🔧 Resources Required
| Component | Quantity |
| --- | --- |
| Arduino Uno R3 | 1 |
| ACS712 5A Current Sensor | 1 |
| 16x2 LCD with I2C Module | 1 |
| Jumper Wires | 10-12 |
| Load - Bulb/Fan | 1 |

## ⚙️ Circuit Connections
| ACS712 Pin | Arduino Pin |
| --- | --- |
| VCC | 5V |
| GND | GND |
| OUT | A0 |

**Note**: Connect ACS712 in series with AC load. Use proper isolation for 230V AC.

| LCD I2C | Arduino Pin |
| --- | --- |
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## 📚 Libraries Required
