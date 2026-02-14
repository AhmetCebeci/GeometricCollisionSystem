/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…  :2
**				ÖĞRENCİ ADI     :AHMET CEBECİ
**				ÖĞRENCİ NUMARASI:B231210077
**				DERS GRUBU		:1C
****************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

// N2b sınıfı : 2 Boyutlu Kartezyen koordinat sistemindeki nokta 
class N2b {
protected:
    // n3b erişebilsin diye protected yaptık
    double x;
    double y;

public:
	//kurucu,varsayılan değerler 0
    N2b(double xDegeri = 0, double yDegeri = 0) {
        x = xDegeri;
        y = yDegeri;
    }

    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    void setX(double xDegeri) {
        x = xDegeri;
    }
    void setY(double yDegeri) {
        y = yDegeri;
    }

	// (+) operatör aşırı yükleme,2 noktayı toplar ve yeni noktayı döndürür
    N2b operator+(const N2b& digerNokta) const {
		// yeni x ve y hesaplanır ve yeni N2b nesnesi döndürülür
        return N2b(x + digerNokta.x, y + digerNokta.y);
    }
};
// N3b Sınıfı: 3 Boyutlu nokta, N2b den kalıtım aldı
class N3b : public N2b {
private:
    double z;

public:
	// kurucu, varsayılan değerler 0,x ve y için N2b kurucusu çağrılır
    N3b(double xDegeri = 0, double yDegeri = 0, double zDegeri = 0) : N2b(xDegeri, yDegeri) {
        z = zDegeri;
    }

    double getZ() const {
        return z;
    }
    void setZ(double zDegeri) {
        z = zDegeri;
    }

	// (+) Operatör Aşırı Yükleme iki N3b noktasını toplayıp yeni nokta döndürür
    N3b operator+(const N3b& digerNokta) const {
        return N3b(x + digerNokta.x, y + digerNokta.y, z + digerNokta.z);
    }
};











// Geo2D Sınıfı: 2 Boyutlu geometrik nesnelerin parent sınıfı 
class Geo2D {
protected:
	N2b merkez; // Bu sınıftan kalıtım alacak tüm 2D şekillerin bir merkezi vardır,bu merkezi de n2b nesnesi ile temsil ettik

public:
    // Kurucu
    Geo2D(N2b merkezNoktasi = N2b()) {
        merkez = merkezNoktasi;
    }

    N2b getMerkez() const {
        return merkez;
    }
    void setMerkez(N2b m) {
        merkez = m;
    }
};
// Kare Sınıfı Geo2D sınıfından türetildi
class Kare : public Geo2D {
private:
    double kenar;

public:
    // Kurucu merkez noktası ve kenar uzunluğu alır
    Kare(N2b merkezNoktasi, double kenarUzunlugu) : Geo2D(merkezNoktasi) {
        kenar = kenarUzunlugu;
    }

    double getKenar() const {
        return kenar;
    }
    void setKenar(double k) {
        kenar = k;
    }
};

// Dikdortgen Sınıfı Geo2D sınıfından kalıtım aldı
class Dikdortgen : public Geo2D {
private:
    double en;
    double boy;

public:
    // Kurucu Merkez, en ve boy aldı
    Dikdortgen(N2b merkezNoktasi, double enUzunlugu, double boyUzunlugu) : Geo2D(merkezNoktasi) {
        en = enUzunlugu;
        boy = boyUzunlugu;
    }

    double getEn() const {
        return en;
    }
    double getBoy() const {
        return boy;
    }
};

// Cember Sınıfı Geo2D sınıfından türetildi
class Cember : public Geo2D {
private:
    double yaricap;

public:
    // Kurucu Merkez ve yarıçap alır
    Cember(N2b merkezNoktasi, double r) : Geo2D(merkezNoktasi) {
        yaricap = r;
    }

    double getYaricap() const {
        return yaricap;
    }
    void setYaricap(double r) {
        yaricap = r;
    }
};











// Geo3D Sınıfı: 3 Boyutlu geometrik nesnelerin parent sınıfı
class Geo3D {
protected:
    N3b merkez; // 3D şekillerin merkezi N3b nesnesi (x,y,z) 

public:
    Geo3D(N3b merkezNoktasi = N3b()) {
        merkez = merkezNoktasi;
    }

    N3b getMerkez() const {
        return merkez;
    }
    void setMerkez(N3b m) {
        merkez = m;
    }
};

// Küre Sınıfı: Geo3D'den türetildi
class Kure : public Geo3D {
private:
    double yaricap;

public:
    // Kurucu Merkez ve yarıçap alır
    Kure(N3b merkezNoktasi, double r) : Geo3D(merkezNoktasi) {
        yaricap = r;
    }

    double getYaricap() const {
        return yaricap;
    }
    void setYaricap(double r) {
        yaricap = r;
    }
};

// Silindir Sınıfı: Geo3D'den türetildi
class Silindir : public Geo3D {
private:
    double yaricap;
    double yukseklik;

public:
    // Kurucu Merkez, yarıçap ve yükseklik alır
    Silindir(N3b merkezNoktasi, double r, double h) : Geo3D(merkezNoktasi) {
        yaricap = r;
        yukseklik = h;
    }

    double getYaricap() const {
        return yaricap;
    }
    double getYukseklik() const {
        return yukseklik;
    }
    void setYaricap(double r) {
        yaricap = r;
    }
    void setYukseklik(double h) {
        yukseklik = h;
    }
};









// Statik çarpışma Sınıfı
class Carpisma {
public:
    // İki Dikdörtgenin Çarpışma Test fonksiyonu
    static bool dikdortgenCarpisma(const Dikdortgen& d1, const Dikdortgen& d2) {
        // İki dikdörtgenin merkezleri arasındaki mesafe hesaplanır
        double xMesafesi = abs(d1.getMerkez().getX() - d2.getMerkez().getX());
        double yMesafesi = abs(d1.getMerkez().getY() - d2.getMerkez().getY());

        // Genişlik ve Yüksekliklerin yarılarının toplamı
        double genislikSiniri = (d1.getEn() + d2.getEn()) / 2.0;
        double yukseklikSiniri = (d1.getBoy() + d2.getBoy()) / 2.0;

        // Eğer merkezler arası mesafe, kenar yarıları toplamından küçükse çarpışma vardır
        if (xMesafesi <= genislikSiniri && yMesafesi <= yukseklikSiniri) {
            return true;
        }
        return false;
    }

    // İki Karenin Çarpışma Test fonksiyonu
    // Kareler de aslında dikdörtgendir, aynı mantık kullanılır.
    static bool kareCarpisma(const Kare& k1, const Kare& k2) {
        double xMesafesi = abs(k1.getMerkez().getX() - k2.getMerkez().getX());
        double yMesafesi = abs(k1.getMerkez().getY() - k2.getMerkez().getY());

        double kenarSiniri = (k1.getKenar() + k2.getKenar()) / 2.0;

        // Hem X hem Y ekseninde kesişme olmalı
        if (xMesafesi <= kenarSiniri && yMesafesi <= kenarSiniri) {
            return true;
        }
        return false;
    }

    //  İki Çemberin Çarpışma Test fonksiyonu
    // Merkezler arası mesafe, yarıçaplar toplamından küçük veya eşitse çarpışırlar.
    static bool cemberCarpisma(const Cember& c1, const Cember& c2) {
        double dx = c1.getMerkez().getX() - c2.getMerkez().getX();
        double dy = c1.getMerkez().getY() - c2.getMerkez().getY();

        // Hipotenüs (Merkezler arası uzaklık)
        double mesafe = sqrt(dx * dx + dy * dy);

        // Çarpışma koşulu
        if (mesafe <= (c1.getYaricap() + c2.getYaricap())) {
            return true;
        }
        return false;
    }

    // Dikdörtgen ve Çember Çarpışma Testi 
    // Çemberin merkezine en yakın dikdörtgen üzerindeki noktayı bulup mesafeyi ölçeriz.
    static bool dikdortgenCemberCarpisma(const Dikdortgen& d, const Cember& c) {
        // Çemberin merkez koordinatları
        double cemberX = c.getMerkez().getX();
        double cemberY = c.getMerkez().getY();

        // Dikdörtgenin sınırlarını belirleme (merkez noktası dikdörtgenin tam ortasıdır)
        double dikdortgenMinX = d.getMerkez().getX() - (d.getEn() / 2.0);
        double dikdortgenMaxX = d.getMerkez().getX() + (d.getEn() / 2.0);
        double dikdortgenMinY = d.getMerkez().getY() - (d.getBoy() / 2.0);
        double dikdortgenMaxY = d.getMerkez().getY() + (d.getBoy() / 2.0);

        // Çemberin merkezine dikdörtgen üzerinde en yakın noktayı bulma
        // çember dikdörtgenin içindeyse, en yakın nokta çember merkezi ile aynı olur.
        double enYakinX = max(dikdortgenMinX, min(cemberX, dikdortgenMaxX));
        double enYakinY = max(dikdortgenMinY, min(cemberY, dikdortgenMaxY));

        // En yakın nokta ile çember merkezi arasındaki mesafeyi hesaplama
        double dx = cemberX - enYakinX;
        double dy = cemberY - enYakinY;

        // Eğer mesafe yarıçaptan küçükse çarpışma vardır 
        double mesafeKaresi = (dx * dx) + (dy * dy);

        if (mesafeKaresi <= (c.getYaricap() * c.getYaricap())) {
            return true;
        }
        return false;
    }

    // İki Kürenin Çarpışma Test fonksiyonu
    // 3D uzayda merkezler arası mesafe <= yarıçaplar toplamı
    static bool kureCarpisma(const Kure& k1, const Kure& k2) {
        double dx = k1.getMerkez().getX() - k2.getMerkez().getX();
        double dy = k1.getMerkez().getY() - k2.getMerkez().getY();
        double dz = k1.getMerkez().getZ() - k2.getMerkez().getZ();

        // 3 Boyutlu mesafe formülü
        double mesafe = sqrt(dx * dx + dy * dy + dz * dz);

        if (mesafe <= (k1.getYaricap() + k2.getYaricap())) {
            return true;
        }
        return false;
    }

    // İki Silindirin Çarpışma Test fonksiyonu
    // (silindirlerin z eksenine paralel olduğunu varsayıyoruz)
    // Hem taban daireleri çarpışmalı (XY düzleminde) HEM DE yükseklikleri çakışmalı (Z ekseninde).
    static bool silindirCarpisma(const Silindir& s1, const Silindir& s2) {
        // 1. Adım: XY Düzleminde Daire Çarpışması Kontrolü
        double dx = s1.getMerkez().getX() - s2.getMerkez().getX();
        double dy = s1.getMerkez().getY() - s2.getMerkez().getY();
        double xyMesafe = sqrt(dx * dx + dy * dy);

        bool dairelerCarpiyorMu = xyMesafe <= (s1.getYaricap() + s2.getYaricap());

        // 2. Adım: Z Ekseninde Yükseklik Çakışması Kontrolü
        double zFarki = abs(s1.getMerkez().getZ() - s2.getMerkez().getZ());
        double yukseklikSiniri = (s1.getYukseklik() + s2.getYukseklik()) / 2.0;

        bool yuksekliklerCakisiyorMu = zFarki <= yukseklikSiniri;

        // Her iki koşul da sağlanmalı
        if (dairelerCarpiyorMu && yuksekliklerCakisiyorMu) {
            return true;
        }
        return false;
    }
};










// Statik KoordinatDonustur Sınıfı
class KoordinatDonustur {
public:
    // 2B Kartezyen -> 2B Polar dönüşümü
    //  N2b(x, y) ->  N2b(r, theta)
    static N2b K2btoK2bpolar(const N2b& k) {
        double r = sqrt(pow(k.getX(), 2) + pow(k.getY(), 2));
        double theta = atan2(k.getY(), k.getX()); // Radyan cinsinden açı
        // Sonucu N2b nesnesi olarak döndürüyoruz (x=r, y=theta)
        return N2b(r, theta);
    }

    // 2B Polar -> 2B Kartezyen dönüşümü
    //  N2b(r, theta) ->  N2b(x, y)
    static N2b K2bpolartoK2bk(const N2b& p) {
        double r = p.getX();
        double theta = p.getY();
        double x = r * cos(theta);
        double y = r * sin(theta);
        return N2b(x, y);
    }

    // 3B Kartezyen -> 3B Silindirik dönüşümü
    //  N3b(x, y, z) ->  N3b(r, theta, z)
    static N3b K3BtoK3bsilindir(const N3b& k) {
        double r = sqrt(pow(k.getX(), 2) + pow(k.getY(), 2));
        double theta = atan2(k.getY(), k.getX());
        double z = k.getZ();
        // Sonucu N3b nesnesi olarak döndürüyoruz (x=r, y=theta, z=z)
        return N3b(r, theta, z);
    }

    // 3B Silindirik -> 3B Kartezyen dönüşümü
    //  N3b(r, theta, z) ->: N3b(x, y, z)
    static N3b K3bsilindirtoK3B(const N3b& s) {
        double r = s.getX();
        double theta = s.getY();
        double z = s.getZ(); // Z değişmez
        double x = r * cos(theta);
        double y = r * sin(theta);
        return N3b(x, y, z);
    }
};










int main()
{
    // 2D Testler Baslangici
    cout << "2D TESTLER" << endl;

    // Dikdortgen testi icin nesneler
    Dikdortgen d1(N2b(0, 0), 10, 5);
    Dikdortgen d2(N2b(8, 0), 10, 5);

    // Dikdortgen carpisma kontrolu
    if (Carpisma::dikdortgenCarpisma(d1, d2))
        cout << "Dikdortgen: Carpisma VAR" << endl;
    else
        cout << "Dikdortgen: Carpisma YOK" << endl;

    // Kare testi icin nesneler
    Kare k1(N2b(0, 0), 10);
    Kare k2(N2b(5, 5), 10);

    // Kare carpisma kontrolu
    if (Carpisma::kareCarpisma(k1, k2))
        cout << "Kare: Carpisma VAR" << endl;
    else
        cout << "Kare: Carpisma YOK" << endl;

    // Cember testi icin nesneler
    Cember c1(N2b(0, 0), 10);
    Cember c2(N2b(15, 0), 10);

    // Cember carpisma kontrolu
    if (Carpisma::cemberCarpisma(c1, c2))
        cout << "Cember: Carpisma VAR" << endl;
    else
        cout << "Cember: Carpisma YOK" << endl;

    // Dikdortgen ve Cember testi icin nesneler
    Dikdortgen dTest(N2b(0, 0), 10, 10);
    Cember cTest(N2b(6, 0), 2);

    // Dikdortgen ve Cember carpisma kontrolu
    if (Carpisma::dikdortgenCemberCarpisma(dTest, cTest))
        cout << "Dikdortgen-Cember: Carpisma VAR" << endl;
    else
        cout << "Dikdortgen-Cember: Carpisma YOK" << endl;


    // 3D Testler Baslangici
    cout << endl << "3D TESTLER" << endl;

    // Kure testi icin nesneler
    Kure kure1(N3b(0, 0, 0), 10);
    Kure kure2(N3b(15, 0, 0), 10);

    // Kure carpisma kontrolu
    if (Carpisma::kureCarpisma(kure1, kure2))
        cout << "Kure: Carpisma VAR" << endl;
    else
        cout << "Kure: Carpisma YOK" << endl;

    // Silindir testi icin nesneler
    Silindir s1(N3b(0, 0, 0), 5, 10);
    Silindir s2(N3b(2, 0, 5), 5, 10);

    // Silindir carpisma kontrolu
    if (Carpisma::silindirCarpisma(s1, s2))
        cout << "Silindir: Carpisma VAR" << endl;
    else
        cout << "Silindir: Carpisma YOK" << endl;


    // Koordinat Donusum Testleri
    cout << endl << "KOORDINAT DONUSUM" << endl;

    // Kartezyen -> Polar
    N2b k2b(3, 4);
    N2b polar = KoordinatDonustur::K2btoK2bpolar(k2b);
    cout << "Kartezyen(3,4) -> Polar r: " << polar.getX() << " theta: " << polar.getY() << endl;

    // Polar -> Kartezyen
    N2b geriK2b = KoordinatDonustur::K2bpolartoK2bk(polar);
    cout << "Polar -> Kartezyen x: " << geriK2b.getX() << " y: " << geriK2b.getY() << endl;

    // 3D Kartezyen -> Silindirik
    N3b k3b(3, 4, 10);
    N3b silindirik = KoordinatDonustur::K3BtoK3bsilindir(k3b);
    cout << "Kartezyen(3,4,10) -> Silindirik r: " << silindirik.getX() << " theta: " << silindirik.getY() << " z: " << silindirik.getZ() << endl;

    return 0;
}

