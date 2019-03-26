Banka Simülasyonu Ödevi
Müşterilerine 3 adet gişe ile hizmet veren bir banka şubesinin simülasyon programı yazılacaktır.
Müşteriler 0 ile 5 dakika aralığında rasgele olarak belirlenen aralıklarda gelmekte ve hizmet almak istemektedirler.
Müşteriler bankaya geldikleri anda, ilk giren ilk çıkar (FIFO) mantığına göre işleyen ve kapasitesi 100 olan bir bekleme kuyruğuna yerleştirilmektedirler.
Bir müşteri kuyruğun en önüne geldiğinde, en az 1 tane boş gişe varsa boş gişelerden birisi tarafından hizmet verilmektedir,
hiç boş gişe yoksa bir tanesinin boşalmasını beklemekte ve boşalan gişe tarafından hizmet verilmektedir.
Bir gişe boşaldığında, hemen sonraki müşteriye hizmet vermeye başlamakta ve bir müşterinin kuyruğun önünden herhangi 
bir gişeye gitmesi hiç zaman almamaktadır. Herhangi bir gişenin herhangi bir müşteriye verdiği hizmet süresi için öncelikle müşterinin
işlemi belirlenmelidir. Müşterinin yapacağı işlemler aşağıdaki gibidir.
•	EFT (3 ile 10 dakika arası)
•	Kredi Çekme (10 ile 20 dakika arası)
•	Fatura Ödeme (2 ile 12 dakika arası)
•	Para Çekme (1 ile 7 dakika arası)

Müşteriye sıra geldiğinde önce rastgele olarak yapacağı işlem belirlenecek daha sonra yine rastgele olarak işlem süresi hesaplanacaktır.
Bir müşteriye verilen hizmet bittiğinde, müşteri hemen gişeyi terk etmekte ve gişe boş olmaktadır.
Müşteriler, 1’den başlayarak bankaya geliş sıralarını gösteren sayılar kullanılarak isimlendirilmektedir (Müşteri-1, Müşteri-2 v.b. gibi).
Aynı anda (aynı dakika içerisinde) birden fazla müşteri gelmesi durumunda, öncelikle sıra numarası küçük olan müşteri kuyruğa yerleştirilmektedir.
Gişeler de aynı şekilde 1’den başlayarak sıra numaraları ile isimlendirilmektedir (Gişe-1, Gişe-2 ve Gişe-3).
Bir müşterinin hizmet alma sırası geldiğinde birden fazla gişe boşsa, müşteri sıra numarası küçük olan gişeye gitmektedir.
Kullanıcı, rasgele sayı üretimi için başlangıç/çekirdek değerini (srand(...)) ve toplam simülasyon süresini (dakika) girmeli ve srand() fonksiyonu,
verilen argüman (çekirdek) ile programın başında 1 kez çalıştırılmalıdır. Bir müşteri kuyruğa eklendikten hemen sonra, bir sonraki müşterinin ne kadar süre sonra geleceği rasgele (0-5 dakika) belirlenmelidir.
Benzer şekilde, bir müşteri boş bir gişeye gitmeden hemen önce, hizmet süresi belirlenmelidir. Belirli bir dakika içerisinde hem bankaya gelen müşterileri kuyruğa ekleme hem de hizmet sırası gelen müşterileri
kuyruktan alıp boş gişelere gönderme işlemlerinin yapılması gerekiyorsa, kuyruğa müşteri ekleme işlemi önce yapılmalıdır.
Simülasyon süresince bankada meydana gelecek aşağıda belirtilen olaylar zaman sırasına göre ekrana yazdırılmalıdır: 
• bir müşterinin bankaya ne zaman geldiği
• ne zaman ve hangi gişede hizmet verilmeye başlandığı
• ne zaman ve hangi gişeyi terk ettiği
Simülasyon bitiminde kuyrukta bekleyen müşteriler varsa onlara da hizmet verildikten sonra, aşağıda belirtilen istatistiksel sonuçlar görüntülenmelidir:
• herhangi bir zamanda kuyrukta bekleyen en fazla müşteri sayısı
• kuyrukta en uzun süre bekleyen müşterinin bekleme süresi
• bir müşterinin kuyrukta ortalama bekleme süresi
