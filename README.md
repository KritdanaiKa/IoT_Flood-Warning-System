# IoT_Flood-Warning-System
การแจ้งเตือนอุทกภัยผ่านเว็บไซต์ และแอปพลิเคชันไลน์ (Flood warning System)

## สมาชิกในกลุ่ม
1. 64100662 นายกฤษณ์ดนัย แก้วมาก
2. 64106065 นางสาวธันยพร จู่ทิ่น
3. 64110588 นางสาวภัทรภร ร่าหมาน

## บทนำ
  ทางกลุ่มผู้จัดทำโครงการได้เล็งเห็นถึงความสำคัญ เรื่องความเป็นอยู่ของผู้คน ที่ประสบปัญหาน้ำท่วมครัวเรือน ซึ่งปัญหาน้ำท่วมเป็นหนึ่งในภัยธรรมชาติที่สามารถก่อให้เกิดความเสียหายร้ายแรง และเสียหายทางทรัพย์สิน การใช้เทคโนโลยี IoT ในการตรวจจับน้ำท่วมไม่เพียงแต่ช่วยลดความเสี่ยง แต่ยังช่วยเพิ่มความรวดเร็วในการรับทราบ และตอบสนองต่อสถานการณ์ฉุกเฉินอย่างมีประสิทธิภาพ  
  เนื่องด้วยสภาพอากาศในปัจจุบันมีความแปรปรวนเป็นอย่างมาก  และในภาคใต้ของประเทศไทย เป็นพื้นที่ที่มีฝนตกชุกตลอดทั้งปี และเป็นพื้นที่ที่เสี่ยงต่อปัญหาน้ำท่วมอย่างต่อเนื่อง เนื่องจากตำแหน่งภูมิภาคที่ต่ำรวมถึงปริมาณน้ำฝนที่มหาศาลที่ได้รับในช่วงฤดูฝน ปัญหานี้ไม่เพียงแต่สร้างความเสียหายทางทรัพย์สินและอาคาร แต่ยังมีผลกระทบต่อเศรษฐกิจและคุณภาพชีวิตของประชาชนในพื้นที่ด้วย
	ทางกลุ่มผู้จัดทำจึงมุ่งเน้นในการทำอุปกรณ์ IoT ขึ้นเพื่อช่วยตรวจวัดระดับน้ำ จากบริเวณแม่น้ำ โดยตรวจวัดระดับความสูงของทุ่นลอยน้ำ ซึ่งแบ่งสภาวะระดับน้ำเป็น 4 ระดับ ได้แก่ ธงสีเขียว ระดับน้ำไม่เกิน 1.30 เมตร ธงสีเหลือง ระดับน้ำ 1.31-1.50 เมตร ธงสีส้ม ระดับน้ำ 1.50-1.80 เมตร ธงสีแดง ระดับน้ำ 1.81 เมตรขึ้นไป โดยจะแจ้งเตือนผลผ่านเว็บไซต์และแอปพลิเคชันไลน์ เพื่อบอกถึงสภาวะระดับน้ำ, คำแนะนำ, เบอร์โทรติดต่อเทศบาล  และระดับน้ำปัจจุบัน
  วัตถุประสงค์ของโครงงานนี้ คือการนำเทคโนโลยี IoT ที่มีอยู่มาใช้ในการตรวจวัดระดับน้ำ โดยวัดจากความสูงของทุ่นลอยน้ำ และแสดงผลระดับน้ำว่าอยู่ระดับใด พร้อมคำแนะนำ ช่วยให้ผู้ใช้งานทราบถึงสถานการณ์น้ำได้แบบเรียลไทม์ ซึ่งจะช่วยให้ผู้ใช้งานสามารถเตรียมรับมือกับสถานการณ์น้ำได้ทันท่วงที เช่น หากระดับน้ำเริ่มสูงขึ้น ผู้ใช้งานสามารถอพยพออกจากพื้นที่ได้ทัน หรือหากระดับน้ำกำลังลดลง ผู้ใช้งานสามารถเตรียมความพร้อมสำหรับการเกษตรหรือกิจกรรมทางน้ำได้	

## การออกแบบระบบ
### สถาปัตยกรรมระบบ
![Arh](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/System%20Ach.png)

จากสถาปัตยกรรมระบบนี้ เป็นสถาปัตยกรรมของระบบการแจ้งเตือนอุทกภัยผ่านเว็บไซต์ และแอปพลิเคชันไลน์ (Flood warning System) แบ่งเป็น 3 โมดูล ดังนี้

โมดูลที่ 1 คือ Microtroller & Sensors เป็นโมดูลที่เกี่ยวกับอุปกรณ์ในด้าน Hardware ต่าง ๆ โดยส่วนของ Arduino UNO จะทำหน้าที่ในการเก็บค่าข้อมูลที่ได้มาจาก Sensor Ultrasonic  Module HC-SR04 และทำการส่งข้อมูลผ่าน Arduino UNO ไปยัง Node MCU  หากมีค่าระดับที่อยู่ในเกณฑ์ทั้ง 4 ระดับ ได้แก่ ระดับน้ำไม่เกิน 1.30 เมตร ระดับน้ำ 1.31-1.50 เมตร ระดับน้ำ 1.50-1.80 เมตร และระดับน้ำ 1.81 เมตรขึ้นไป จากนั้นจะส่งข้อมูลไปยังแอปพลิเคชันไลน์ (Line Application)  สำหรับเว็บไซต์จะส่งค่าไปยัง MQTT Broker และส่งข้อมูลเข้า Json Server เพื่อเก็บประวัติข้อมูลของระดับน้ำ และใช้ Flask Service ดึงข้อมูลจาก WEB API  Json Server เพื่อส่งไปยังหน้าเว็บไซต์ (Website) 

โมดูลที่ 2 คือ Backend เป็นโมดูลที่เกี่ยวกับการประสานงานในการรับส่งข้อมูล โดยผู้ใช้ส่งคำขอข้อมูลการระดับน้ำ ซึ่งประกอบด้วย MQTT Broker ทำหน้าที่เป็นตัวกลางในการส่งข้อมูลไปยัง Json Server และส่งต่อไปยัง Flask Service และ Flask Servic ทำหน้าที่เรียกใช้ API จาก Json Server เพื่อส่งข้อมูลไปยังหน้าเว็บไซต์ (Website)  เป็นตัวติดต่อกันระหว่าง Json Server และ Frontend

โมดูลที่ 3 คือ Frontend เป็นโมดูลที่เกี่ยวกับการแสดงผลข้อมูลต่าง ๆ ได้แก่ เวลาปัจจุบัน ระดับน้ำ ระดับความเสี่ยง คำแนะนำ และกราฟแสดงระดับในแต่ละวัน ที่ได้รับมาจาก Json Server เพื่อแจ้งเตือนการเกิดอุทกภัย และระดับความเสี่ยง เพื่อให้ผู้ใช้สามารถทราบถึงความเสี่ยงและเตรียมตัวรับมือได้ทันท่วงที
### สถาปัตยกรรมซอฟต์แวร์
![Arh](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/Software%20Ach.png)

โมดูลสำหรับการใช้งานผ่าน Web Frontend โดยผู้ใช้จะต้องทำการเข้าใช้งาน Website ก่อนที่จะรับข้อมูล จากนั้นระบบจะทำการดึงค่าจาก Web API Server มาทำการแสดงผลบนหน้า Website 

จากนั้นระบบจะส่งค่าของระดับน้ำ จาก Website ผ่าน MQTT Broker ไปยัง Microtroller เพื่อส่งค่าระดับน้ำแจ้งเตือนไปยังหน้าเว็บไซต์ โดยโมดูลนี้จะประกอบไปด้วย 5 องค์ประกอบหลัก ได้แก่

1.	User : ผู้ใช้งาน
2.	Web Frontend : หน้าเว็บไซต์ ( Website) สำหรับแสดงค่าระดับน้ำ
3.	Web API Server : API ที่ใช้สำหรับรับและส่งข้อมูลบนหน้าเว็บไซต์ ( Website) 
4.	Database : ฐานข้อมูลสำหรับเก็บข้อมูลระดับน้ำ
5.	MQTT Broker : ตัวกลางที่ทำหน้าที่รับส่งข้อมูลระหว่าง Web API Server และ Microtroller

ซึ่งโมดูลนี้สามารถนำไปประยุกต์ใช้กับระบบตรวจจับวัตถุ ระบบตรวจจับระยะทาง ระบบการตรวจจับการบุกรุก และระบบควบคุมการสั่งเปิดปิดประตู เป็นต้น

### โครงสร้างข้อมูลในแต่ละโมดูล
ข้อมูลที่รับจากSensor จะถูกจัดเก็บในรูปแบบโครงสร้างของ JSON ที่จะประกอบไปด้วยข้อมูลของ id และ message ตามลำดับ ที่ถูกจัดเก็บใน Module ชื่อ water_level
```
{
  "water_level": [
    {
      "message": "{\"waterlavel\":2.130000}",
      "id": 1
    }
  ]
}
```
| Attribute  | คำอธิบาย | ตัวอย่างข้อมูล | ตัวอย่างข้อมูล |
| ------------- | ------------- | ------------- | ------------- |
| id  | รหัสของระดับน้ำที่บันทึก  | int  |  1 |
| message  | ระดับน้ำในแม่น้ำ/คลอง | String  |  {\"waterlavel\":213.550000} |

## การพัฒนาระบบ
### Board
1. Arduino UNO ทำหน้าที่รับค่าและประมวลผลค่าระยะทางจากเซนเซอร์ Ultrasonic Sensor Module HC-SR04 และส่งค่าไปยัง Serial และส่งค่าไปยัง LCD
2. ESP8266 ทำหน้าที่รับค่าจาก Serial และส่งข้อมูลไปยัง MQTT Broker 
### Sensors
1. Ultrasonic Sensor Module HC-SR04 ทำหน้าที่ในการรับค่าระยะห่างระหว่างเซนเซอร์และวัตถุ
### เครื่องมือ
1. ภาษา C ใช้ในการเขียนคำสั่งลงในบอร์ด เพื่อทำให้บอร์ดสามารถรับค่าและส่งค่าข้อมูลได้
2. MQTT Broker ใช้เป็นตัวกลางในการรับข้อมูลจาก Node MCU และส่งไปยัง JSON Server
3. JavaScript ใช้ในการควบคุมฟังก์ชันของ Frontend และส่ง Web API ไปยัง Flask service
4. HTML ใช้ในการแสดงผลข้อมูลแก่ผู้ใช้
5. Python : Flask ใช้สำหรับเป็น Web API ในการรับข้อมูลจาก JavaScript ไปยัง JSON Server และ MQTT เป็น Framework ในการเชื่อมต่อ IoT ขึ้นเว็บไซต์ สำหรับดึงข้อมูลจาก JSON Server ร่วมกับส่งค่าสถานะไปยังบอร์ด เพื่อแจ้งเตือนผ่านแอปพลิเคชันไลน์และเว็บไซต์
### ไลบารี
1. Wire: ใช้สำหรับการสื่อสารผ่าน I2C (Inter-Integrated Circuit) ซึ่งเป็นโปรโตคอลการสื่อสารระหว่างอุปกรณ์ในระบบที่เชื่อมต่อกันผ่านสายสัญญาณสองเส้น (SDA - Serial Data Line และ SCL - Serial Clock Line)
2. LiquidCrystal_I2C: ใช้สำหรับการควบคุมการทำงานของหน้าจอ LCD (Liquid Crystal Display) ที่เชื่อมต่อผ่าน I2C. ช่วยในการแสดงข้อความหรือตัวเลขบนหน้าจอ LCD อย่างสะดวก
3. ESP8266WiFi: ใช้สำหรับการเชื่อมต่อ WiFi ของ ESP8266 (เช่น NodeMCU) เพื่อทำให้ไมโครคอนโทรลเลอร์สามารถเข้าถึงเครือข่ายไร้สายได้
4. TridentTD_LineNotify: ช่วยในการส่งข้อความแจ้งเตือนไปยัง Line Notify ซึ่งเป็นบริการที่ให้บริการการแจ้งเตือนผ่านแอปพลิเคชัน Line
5. PubSubClient: เป็นไลบรารีที่ใช้สำหรับการเข้ารหัสและถอดรหัสข้อมูลที่ส่งผ่าน MQTT (Message Queuing Telemetry Transport) protocol. ช่วยในการเชื่อมต่อและสื่อสารกับโมโนทคอนโทรลเลอร์ที่รองรับ MQTT
6. HCSR04: ใช้สำหรับติดต่อกับเซนเซอร์วัดระยะทาง Ultrasonic (HCSR04) เพื่อวัดระยะทางด้วยคลื่นเสียง ultrasonic และได้ค่าระยะทางออกมา

## การทดสอบ
จากภาพข้างต้นเป็นภาพที่ใช้ในการทดสอบ
### 1. Test Case #1 
![Test](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/Test1.jpg)

ทำการทดสอบด้วยการติดตั้งชุดเซ็นเซอร์จากนั้นจำลองกระทงเป็นทุ่นลอยน้ำ วางในระยะที่ 1  ซึ่งมีระดับน้ำไม่เกิน 1.30 เมตร 

ผลการทดสอบครั้งที่ 1 
![Webpage](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/%E0%B8%A3%E0%B8%B0%E0%B8%94%E0%B8%B1%E0%B8%9A%E0%B8%9B%E0%B8%81%E0%B8%95%E0%B8%B4.jpg)
![Line](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/IMG_3699.jpg)
ภาพผลลัพธ์การแสดงผลระดับน้ำระดับที่ 1 
### 2. Test Case #2 
![Test](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/Test2.jpg)

ทำการทดสอบด้วยการติดตั้งชุดเซ็นเซอร์จากนั้นจำลองกระทงเป็นทุ่นลอยน้ำ วางในระยะที่ 2  ซึ่งมีระดับน้ำตั้งแต่ 1.30 - 1.50 เมตร 

ผลการทดสอบครั้งที่ 2
![Webpage](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/%E0%B8%A3%E0%B8%B0%E0%B8%94%E0%B8%B1%E0%B8%9A%E0%B8%9B%E0%B8%B2%E0%B8%99%E0%B8%81%E0%B8%A5%E0%B8%B2%E0%B8%87.jpg)
![Line](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/IMG_3700.jpg)
ภาพผลลัพธ์การแสดงผลระดับน้ำระดับที่ 2
### 3. Test Case #3 
![Test](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/Test3.jpg)

ทำการทดสอบด้วยการติดตั้งชุดเซ็นเซอร์จากนั้นจำลองกระทงเป็นทุ่นลอยน้ำ วางในระยะที่ 3 ซึ่งมีระดับน้ำตั้งแต่ 1.51 - 1.80 เมตร 

ผลการทดสอบครั้งที่ 3
![Webpage](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/%E0%B8%A3%E0%B8%B0%E0%B8%94%E0%B8%B1%E0%B8%9A%E0%B8%AD%E0%B8%B1%E0%B8%99%E0%B8%95%E0%B8%A3%E0%B8%B2%E0%B8%A2.jpg)
![Line](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/IMG_3701.jpg)
ภาพผลลัพธ์การแสดงผลระดับน้ำระดับที่ 3
### 4. Test Case #4 
![Test](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/Test4.jpg)

ทำการทดสอบด้วยการติดตั้งชุดเซ็นเซอร์จากนั้นจำลองกระทงเป็นทุ่นลอยน้ำ วางในระยะที่  4  ซึ่งมีระดับน้ำตั้งแต่ 1.81 ขึ้นไป

ผลการทดสอบครั้งที่ 4
![Webpage](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/%E0%B8%A3%E0%B8%B0%E0%B8%94%E0%B8%B1%E0%B8%9A%E0%B8%AD%E0%B8%B1%E0%B8%99%E0%B8%95%E0%B8%A3%E0%B8%B2%E0%B8%A2%E0%B8%AA%E0%B8%B9%E0%B8%87%E0%B8%AA%E0%B8%B8%E0%B8%94.jpg)
![Line](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/IMG_3702.jpg)
ภาพผลลัพธ์การแสดงผลระดับน้ำระดับที่ 4
### 5. Test Case #5
![Test](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/Test5.jpg)

ทำการทดสอบด้วยการติดตั้งชุดเซ็นเซอร์จากนั้นจำลองกระทงเป็นทุ่นลอยน้ำ จากระดับน้ำในระดับที่ 4 ซึ่งมีระดับน้ำตั้งแต่ 1.81 ขึ้นไป กลับไปวางในระยะที่ 1  ซึ่งมีระดับน้ำตั้งแต่ 1.31 - 1.50 เมตร 

ผลการทดสอบครั้งที่ 5
![Web](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/%E0%B8%A3%E0%B8%B0%E0%B8%94%E0%B8%B1%E0%B8%9A%E0%B8%9B%E0%B8%81%E0%B8%95%E0%B8%B4.jpg)
![Webpage_Graph](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/%E0%B9%81%E0%B8%9C%E0%B8%99%E0%B8%A0%E0%B8%B9%E0%B8%A1%E0%B8%B4%E0%B8%A3%E0%B8%B0%E0%B8%94%E0%B8%B1%E0%B8%9A%E0%B8%99%E0%B9%89%E0%B8%B3.jpg)
![Line](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/IMG_3703.jpg)
ภาพผลลัพธ์การแสดงผลระดับน้ำระดับที่ 5

## สรุปผลการทดสอบ
จากผลการทดลองทั้ง 5 กรณีตามการทดสอบข้างต้น พบว่าตรงตามวัตุประสงค์ที่ตั้งไว้ โดย Arduino UNO สามารถรับค่าจาก Ultrasonic Sensor แล้วจึงส่งค่าไปยัง MQTT Broker ได้เพื่อนำข้อมูลไปเก็บไว้ยัง JSON Server และ ผ่านทาง Line Notify หลังจากนั้น Flask Service จะทำการดึงข้อมูลจาก JSON Server เพื่อนำไปแสดงผ่านหน้าเว็บไซต์ได้ โดยเว็บไซต์สามารถแสดงข้อมูล เวลาปัจจุบัน ระดับน้ำ ระดับความเสี่ยง คำแนะนำ และกราฟแสดงระดับในแต่ละวันได้ตามเกณฑ์ที่กำหนดไว้ได้
## Demo
[![IoT_Flood-Warning-System](https://github.com/KritdanaiKa/IoT_Flood-Warning-System/blob/main/%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%81%E0%B8%AD%E0%B8%9A/%E0%B8%9B%E0%B8%81%E0%B8%84%E0%B8%A5%E0%B8%B4%E0%B8%9B.jpg)](https://youtu.be/fT4qFuj1Mpk?si=399r6q4nWpxpzUuR)
