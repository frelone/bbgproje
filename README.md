# Triversi Oyunu

Bu proje, klasik Reversi (Othello) oyununun bir uyarlamasıdır. Oyunda standart kuralların yanı sıra ek özellikler ve stratejik hamlelerin önem kazandığı bazı geliştirmeler bulunmaktadır. Terminal tabanlı bu oyun, hem eğlenceli bir deneyim sunar hem de programlama becerilerini geliştirmek için harika bir örnek teşkil eder.

## Özellikler

- **Klasik Reversi Kuralları**: Oyunda taşların yerleştirilmesi, çevirme mekanikleri ve oyun sonu belirlemesi klasik Reversi kurallarına uygun şekilde uygulanır.
- **Hamle Geri Al**: Yanlış bir hamle mi yaptınız? Oyunda hamle geri alma özelliğiyle son hamlenizi iptal edip yeniden oynayabilirsiniz.
- **Hamle Önerileri**: Zorlandığınızda, geçerli hamlelerinizi görmenizi sağlayan bir "hamle öneri" modu mevcuttur.
- **Zorluk Seviyeleri**: Oyun, farklı zorluk seviyelerinde oynanabilir. Başlangıç, orta ve ileri seviyeler arasından seçim yapabilirsiniz.
- **Dinamik Tahta Görüntüleme**: Oyunun her turunda tahta durumu terminalde temiz bir biçimde görüntülenir.
- **Puan Tablosu**: Tahtada her iki oyuncunun taş sayısını ve kazanma olasılığını gösteren bir puan tablosu.

## Değişimler ve İyileştirmeler

1. **Kullanıcı Dostu Arayüz**:
   - Tahta düzeni sadeleştirildi ve taşlar kolayca ayırt edilebilir hale getirildi.
   - Oyuncu hamlelerinde detaylı uyarılar ve yönlendirmeler sağlandı.
   
2. **Hamle Geçişi Otomasyonu**:
   - Artık bir oyuncu hamle yapamayacak durumdaysa oyun otomatik olarak diğer oyuncuya geçiyor.
   - Hamle yapılmadığında "Pas Geç" özelliği devreye giriyor.

3. **Yapay Zeka Geliştirmesi (Opsiyonel)**:
   - Oyun bir yapay zeka oyuncusuyla oynanabilir hale getirildi.
   - Yapay zeka, zorluk seviyesine göre farklı stratejiler uygular:
     - **Kolay Seviye**: Rastgele geçerli bir hamle seçer.
     - **Zor Seviye**: Kazanma olasılığını artıracak hamleleri analiz eder.

4. **Gelişmiş Oyun Sonu Değerlendirmesi**:
   - Oyun sonunda kazanan, kaybeden ve skor farkı detaylı bir şekilde sunulur.
   - Beraberlik durumunda özel bir mesaj görüntülenir.

5. **Performans Optimizasyonu**:
   - Tahta durumlarının kontrol mekanizması hızlandırıldı.
   - Geçerli hamlelerin hesaplanması için kullanılan algoritmalar iyileştirildi.

## Kurulum ve Çalıştırma

1. **Depoyu Klonlayın**:
   ```bash
   git clone https://github.com/frelone/bbgproje.git
