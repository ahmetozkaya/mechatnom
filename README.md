# mechatnom
## uart habeşleşme ve led yakma uygulaması
Main içinde 2 task çalışıyor. (cooperative multitasking)
1. task led on off yapıyor. Örnek (300ms ON 700ms off) on off süreleri ayarlanabilir.    
2. task uart'tan gelen datayı aynı port üzerinden echo yapıyor. Uart interrupt ile çalışıyor ve ayarları değiştirilebilir. Default 115200 8N1
Uart'tan "stop" değeri alındığında echo taskı sonlanıyor ve led 1sn aralıklarla yanıp sönüyor.
Uart'tan "start" değeri alındığında echo taskı yeniden başlıyor ve led bir önceki ayarlarla çalışmaya devam ediyor
Uart'tan "ledOn" ve "ledOff" değeri ile led on veya  led off süresi ayarlanıyor.
Uart'tan "baudrate_hızı" değeri ile haberleşme hızı ayarlanıyor.
Bu 2 task birbirini bloke etmiyor.
