# mechatnom
## uart habeşleşme ve led yakma uygulaması
### Uygulama 
Main içinde 2 task çalışıyor. (cooperative multitasking)
1. task led on off yapıyor. Örnek (300ms ON 700ms off) on off süreleri ayarlanabilir.    
2. task uart'tan gelen datayı aynı port üzerinden echo yapıyor. Uart interrupt ile çalışıyor ve ayarları değiştirilebilir. Default 115200 8N1
Uart'tan "stop" değeri alındığında echo taskı sonlanıyor ve led 1sn aralıklarla yanıp sönüyor.
Uart'tan "start" değeri alındığında echo taskı yeniden başlıyor ve led bir önceki ayarlarla çalışmaya devam ediyor
Uart'tan "ledOn" ve "ledOff" değeri ile led on veya  led off süresi ayarlanıyor.
Uart'tan "baudrate_hızı" değeri ile haberleşme hızı ayarlanıyor.
Bu 2 task birbirini bloke etmiyor.
### Kullanılan IDE ve araçlar
1. STM32CubeIDE 1.7.0 ile oluşturulmuştur.
2. STM studio ile test ve kontrol edilmiştir.
3. Termite 3.3 programı ile Uart haberleşmesi sağlanmıştır.
4. [STM32F4DISCOVERY-DISC1](https://www.st.com/en/evaluation-tools/stm32f4discovery.html)
5. [CP2102 USB-UART modulü](https://www.direnc.net/cp2102-usb-uart-cevirici-usb-a)
