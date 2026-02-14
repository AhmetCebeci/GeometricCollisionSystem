# Geometrik Çarpışma ve Koordinat Dönüşüm Sistemi

Bu proje, Sakarya Üniversitesi Bilgisayar Mühendisliği Bölümü Programlamaya Giriş dersi kapsamında geliştirilen, 2B ve 3B uzayda geometrik nesneleri ve bu nesnelerin etkileşimlerini simüle eden bir C++ uygulamasıdır.

## 🎓 Proje Bilgileri
* **Üniversite:** Sakarya Üniversitesi
* **Fakülte:** Bilgisayar ve Bilişim Bilimleri Fakültesi
* **Bölüm:** Bilgisayar Mühendisliği
* **Ders:** Programlamaya Giriş
* **Öğrenci:** Ahmet Cebeci
* **Öğrenci No:** B231210077

## 🛠️ Teknik Özellikler

### 1. Nesne Yönelimli Tasarım (OOP)
* **Kalıtım (Inheritance):** `N2b` sınıfından türetilen `N3b` ve `Geo2D`/`Geo3D` sınıfları ile hiyerarşik yapı kurulmuştur.
* **Kapsülleme (Encapsulation):** Veri güvenliği için `protected` ve `private` erişim belirleyicileri kullanılmıştır.
* **Operatör Aşırı Yükleme:** Noktalar arasında toplama işlemi yapılabilmesi için `+` operatörü aşırı yüklenmiştir.

### 2. Desteklenen Geometrik Şekiller
* **2 Boyutlu:** Kare, Dikdörtgen ve Çember.
* **3 Boyutlu:** Küre ve Silindir.

### 3. Çarpışma Testleri (Collision Detection)
`Carpisma` sınıfı içerisinde statik olarak tanımlanan algoritmalar şunları kontrol eder:
* İki dikdörtgenin çakışma durumu.
* İki karenin birbirine teması.
* İki çemberin mesafe bazlı çarpışması.
* Dikdörtgen ve çemberin kesişim noktası analizi.
* 3B uzayda iki kürenin ve iki silindirin çarpışma kontrolü.

### 4. Koordinat Dönüştürme
`KoordinatDonustur` sınıfı ile aşağıdaki matematiksel dönüşümler yapılabilmektedir:
* **2B Kartezyen ↔ 2B Polar:** (x, y) koordinatlarından (r, theta) değerlerine geçiş.
* **3B Kartezyen ↔ 3B Silindirik:** (x, y, z) koordinatlarından (r, theta, z) değerlerine geçiş.

## 🚀 Kurulum ve Çalıştırma

1. C++ derleyicinizin (GCC, MSVC vb.) kurulu olduğundan emin olun.
2. `PGHomework2.cpp` dosyasını indirin.
3. Terminal üzerinden aşağıdaki komutla derleyin:
   ```bash
   g++ PGHomework2.cpp -o GeometriOdevi
