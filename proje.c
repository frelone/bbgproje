#include <stdio.h>
int main()
{
    char oyun[23][23];
    char K = 'K', S = 'S', M = 'M';
    int artis = 0, parametre = 0, n, m, k, i, j, k1 = 0, s1 = 0, m1 = 0, tab, orta;
    int true = 1, true1, true2, true3, true4, true5, true6, true7 = 1, true8, true9, true10, true11;
    int yatay, dikey, capraz1, capraz2;
    char mat[3] = {K, S, M};
    printf("\nTRIVERSI OYUNUNA HOSGELDINIZ.\n\n");
    printf("Oyun kurallari sunlardir:\n" 
           "Oyuncularin taslari Kirmizi, Sari, Mavi renklerdedir ve sinirsizdir.\n"
           "Oyun, 1. oyuncunun kirmizi tasini oyun tahtasinin ortasina en yakin koordinata koymasi ile baslar.\n"
           "Sirasiyla 2. oyuncu sari, 3.oyuncu mavi tasini tahtaya diger taslara yatay/dikey/capraz olarak koyar ve oyun bu sekilde devam eder.\n"
           "Renk degisimi icin, yatay/dikey/capraz siranin bir acik ucuna koyulan tas ile o siradaki "
           "ayni renkteki diger en yakin tasin arasindaki diger renklerin tamami, koyulan tasin rengine doner.\n"
           "Oyun tahtada tas koyacak yer kalmadiginda sonlanir ve tahtada en cok tasi olan oyuncu kazanir.\n\n");
           // Yazılarımı başlangıçta ve dolasıyla raporumdaki örneklerde Türkçe klavye kullanrak yazmıştım ama sonrasında her bilgisayarda sıkıntısız çalışması için İngilizce klavyeye döndürdüm.
           
    printf("Lutfen tahtanin bir kenar uzunlugunu giriniz(ornek:10): ");                                                 
    scanf("%d", &tab);
    while (true7)
    {
        if (tab > 23 || tab < 3)
        {
            printf("Lutfen tekrar giriniz ve degeriniz 24 ten kücük ve 2 den büyük olsun.\n");
            scanf("%d", &tab);
        }
        else
        {
            true7 = 0;
        }
    }
    for (int rows = 0; rows < tab; rows++)
    {
        for (int cols = 0; cols < tab; cols++)
        {
            oyun[rows][cols] = '_';
        }
    }
    for (int i = 0; i < tab; i++)
    {
        for (int j = 0; j < tab; j++)
        {
            printf("%c ", oyun[i][j]);
        }
        printf("%c", '\n');
    }

    while (parametre < tab * tab && true)
    {

        true4 = 1;
        while (parametre < tab * tab && true)
        {

            true4 = 1;

            while (parametre < tab * tab && true)
            {
                true4 = 1;

                while (true4) // kullanıcının taşını doğru yere oynayıp oynamadığını her olasılık için kontrol eden döngü
                {
                    printf("Lutfen siradaki oyuncu hamlesini yapsin. (ornek: 3,4): ");
                    scanf("%d,%d", &n, &m);

                    if (n < 0 || n >= tab || m < 0 || m >= tab)
                    {
                        printf("Gecersiz koordinat girdiniz.Tahtanin sinirlari içinde bir deger giriniz.\n");
                    }
                    else if (oyun[n][m] != '_')
                    {
                        printf("Bu koordinat daha once secilmis.Lutfen baska bir koordinat giriniz.\n");
                    }
                    else
                    {
                        if (parametre == 0)
                        {
                            orta = tab / 2;

                            if (tab % 2 != 0)
                            {
                                if (n != orta || m != orta) // tek uzunluklu kenarlar için ilk taşın merkezde oynanmasını sağlıyorum
                                {
                                    printf("Ilk hamle yalnızca tahtanın ortasına yapılabilir.(örnek: %d,%d)\n", orta, orta);
                                }
                                else
                                {
                                    true4 = 0;
                                }
                            }
                            else
                            {
                                if (!((n == orta - 1 && m == orta - 1) || (n == orta && m == orta) || (n == orta - 1 && m == orta) || (n == orta && m == orta - 1))) // çift uzunluklu kenarlar için ilk taşın merkezde oynanmasını sağlıyorum
                                {
                                    printf("Ilk hamle yalnizca tahtanin ortasina yapilabilir.(ornek1: %d,%d) (ornek2: %d,%d)(ornek3: %d,%d) (ornek4: %d,%d)\n", orta, orta, orta - 1, orta, orta, orta - 1, orta - 1, orta - 1);
                                }
                                else
                                {
                                    true4 = 0;
                                }
                            }
                        }

                        else if (parametre > 0) // taş kümesi çevresinde oynanmasını sağlıyorum
                        {

                            true6 = 0;

                            if ((n > 0 && oyun[n - 1][m] != '_') ||
                                (n < tab - 1 && oyun[n + 1][m] != '_') ||
                                (m > 0 && oyun[n][m - 1] != '_') ||
                                (m < tab - 1 && oyun[n][m + 1] != '_') ||
                                (n > 0 && m > 0 && oyun[n - 1][m - 1] != '_') ||
                                (n > 0 && m < tab - 1 && oyun[n - 1][m + 1] != '_') ||
                                (n < tab - 1 && m > 0 && oyun[n + 1][m - 1] != '_') ||
                                (n < tab - 1 && m < tab - 1 && oyun[n + 1][m + 1] != '_'))
                            {
                                true6 = 1;
                            }

                            if (true6)
                            {
                                true4 = 0;
                            }
                            else
                            {
                                printf("Lutfen tahtadaki mevcut taslarin etrafinda oynayin.\n");
                            }
                        }
                    }
                }

                oyun[n][m] = mat[artis];

                true1 = 1;
                yatay = 1;

                while (yatay < tab && true1) // yatayın sağ kısmına bakıyorum
                {
                    if (m + yatay < tab && oyun[n][m] == oyun[n][m + yatay])
                    {

                        for (k = m; k <= m + yatay; k++)
                        {
                            if (oyun[n][k] == '_')
                            {
                                true1 = 0;
                            }
                        }
                        if (true1)
                        {
                            for (k = m; k <= m + yatay; k++)
                            {
                                oyun[n][k] = mat[artis];
                            }
                            true1 = 0;
                        }
                    }
                    else
                    {
                        yatay++;
                    }
                }
                true8 = 1;
                yatay = 1;
                while (yatay < tab && true8) // yatayın sol kısmına bakıyorum
                {

                    if (m - yatay >= 0 && oyun[n][m] == oyun[n][m - yatay])
                    {

                        for (k = m - yatay; k <= m; k++)
                        {
                            if (oyun[n][k] == '_')
                            {
                                true8 = 0;
                            }
                        }
                        if (true8)
                        {
                            for (k = m - yatay; k <= m; k++)
                            {
                                oyun[n][k] = mat[artis];

                                true8 = 0;
                            }
                        }
                    }

                    else
                    {
                        yatay++;
                    }
                }

                true2 = 1;
                dikey = 1;

                while (dikey < tab && true2) // dikeyin üst kısmına bakıyorum
                {
                    if (n + dikey < tab && oyun[n][m] == oyun[n + dikey][m])
                    {

                        for (k = n; k <= n + dikey; k++)
                        {
                            if (oyun[k][m] == '_')
                            {
                                true2 = 0;
                            }
                        }
                        if (true2)
                        {
                            for (k = n; k <= n + dikey; k++)
                            {
                                oyun[k][m] = mat[artis];
                            }
                            true2 = 0;
                        }
                    }
                    else
                    {
                        dikey++;
                    }
                }
                true9 = 1;
                dikey = 1;
                while (dikey < tab && true9) // dikeyin alt kısmına bakıyorum
                {
                    if (n - dikey >= 0 && oyun[n][m] == oyun[n - dikey][m])
                    {

                        for (k = n - dikey; k <= n; k++)
                        {
                            if (oyun[k][m] == '_')
                            {
                                true9 = 0;
                            }
                        }
                        if (true9)
                        {
                            for (k = n - dikey; k <= n; k++)
                            {
                                oyun[k][m] = mat[artis];
                            }
                            true9 = 0;
                        }
                    }

                    else
                    {
                        dikey++;
                    }
                }

                true3 = 1;
                capraz1 = 1;

                while (capraz1 < tab && true3) // sol alt çapraza bakıyorum
                {
                    if (n + capraz1 < tab && m - capraz1 >= 0 && oyun[n][m] == oyun[n + capraz1][m - capraz1])
                    {

                        for (k = 0; k <= capraz1; k++)
                        {
                            if (oyun[n + k][m - k] == '_')
                            {
                                true3 = 0;
                            }
                        }
                        if (true3)
                        {
                            for (k = 0; k <= capraz1; k++)
                            {
                                oyun[n + k][m - k] = mat[artis];
                            }
                            true3 = 0;
                        }
                    }
                    else
                    {
                        capraz1++;
                    }
                }
                capraz1 = 1;
                true10 = 1;

                while (capraz1 < tab && true10) // sağ üst çapraza bakıyorum
                {
                    if (n - capraz1 >= 0 && m + capraz1 < tab && oyun[n][m] == oyun[n - capraz1][m + capraz1])
                    {

                        for (k = 0; k <= capraz1; k++)
                        {
                            if (oyun[n - k][m + k] == '_')
                            {
                                true10 = 0;
                            }
                        }
                        if (true10)
                        {
                            for (k = 0; k <= capraz1; k++)
                            {
                                oyun[n - k][m + k] = mat[artis];
                            }
                            true10 = 0;
                        }
                    }
                    else
                    {
                        capraz1++;
                    }
                }
                true5 = 1;
                capraz2 = 1;

                while (capraz2 < tab && true5) // sağ alt çapraza bakıyorum
                {
                    if (n + capraz2 < tab && m + capraz2 < tab && oyun[n][m] == oyun[n + capraz2][m + capraz2])
                    {

                        for (k = 0; k <= capraz2; k++)
                        {
                            if (oyun[n + k][m + k] == '_')
                            {
                                true5 = 0;
                            }
                        }
                        if (true5)
                        {
                            for (k = 0; k <= capraz2; k++)
                            {
                                oyun[n + k][m + k] = mat[artis];
                            }
                            true5 = 0;
                        }
                    }
                    else
                    {
                        capraz2++;
                    }
                }
                true11 = 1;
                capraz2 = 1;
                while (capraz2 < tab && true11) // sol üst çapraza bakıyorum
                {
                    if (n - capraz2 >= 0 && m - capraz2 >= 0 && oyun[n][m] == oyun[n - capraz2][m - capraz2])
                    {

                        for (k = 0; k <= capraz2; k++)
                        {
                            if (oyun[n - k][m - k] == '_')
                            {
                                true11 = 0;
                            }
                        }
                        if (true11)
                        {
                            for (k = 0; k <= capraz2; k++)
                            {
                                oyun[n - k][m - k] = mat[artis];
                            }
                            true11 = 0;
                        }
                    }
                    else
                    {
                        capraz2++;
                    }
                }

                for (int i = 0; i < tab; i++) // kullanıcı hamleler sonrası tahtadaki değişimleri anlasın diye tahtayı her hamle sonrası yazdırıyorum
                {
                    for (int j = 0; j < tab; j++)
                    {
                        printf("%c ", oyun[i][j]);
                    }
                    printf("%c", '\n');
                }

                if (mat[artis] != M) // oyuncuların sırasıyla değişmesini sağlıyorum
                {
                    artis++;
                }
                else
                {
                    artis = 0;
                }
                parametre++;
            }

            for (i = 0; i < tab; i++) // tahtada her taştan kaçar tane olduğunu sayıyorum
            {
                for (j = 0; j < tab; j++)
                {
                    if (oyun[i][j] == K)
                    {
                        k1++;
                    }
                    else if (oyun[i][j] == S)
                    {
                        s1++;
                    }
                    else if (oyun[i][j] == M)
                    {
                        m1++;
                    }
                }
            }
            printf("Toplam Kirmizi Tas Sayisi:%d\nToplam Sari Tas Sayisi:%d\nToplam Mavi Tas Sayisi:%d\n", k1, s1, m1);
            if (k1 > s1 && k1 > m1)
            {
                printf("Kazanan Renk KIRMIZI\n");
            }
            else if (s1 > k1 && s1 > m1)
            {
                printf("Kazanan Renk SARI\n");
            }
            else if (m1 > k1 && m1 > s1)
            {
                printf("Kazanan Renk MAVI\n");
            }
            else if (k1 == m1 && k1 > s1)
            {
                printf("Kazanan Renkler KIRMIZI ve MAVİ \n");
            }
            else if (k1 == s1 && k1 > m1)
            {
                printf("Kazanan Renkler KIRMIZI ve SARI\n");
            }
            else if (s1 == m1 && s1 > k1)
            {
                printf("Kazanan Renkler SARI VE MAVİ\n");
            }
            else
            {
                printf("Tüm taslar esit ve Kazanan yok\n");
            }
        }
    }
    return 0;
}
