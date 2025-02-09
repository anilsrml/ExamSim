
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//RASTGELE CEVAP ANAHTARININ OLUSTURULDUGU FONKSIYON
// RAND FONKSIYONU ILE RASTGELE CEVAP ANAHTARI OLUSTURULUR
void cevap_anahtari_uret(char cevap_anahtari[], int S){

    int i,j;
    srand(time(0));

    for(i=0;i<S;i++)
    {

        int a = (rand()%5);

        if(a == 0)
        {
            cevap_anahtari[i] = 'A';
        }
        else if(a == 1)
        {
            cevap_anahtari[i] = 'B';
        }
        else if(a == 2)
        {
            cevap_anahtari[i] = 'C';
        }
        else if(a == 3)
        {
            cevap_anahtari[i] = 'D';
        }
        else
        {
            cevap_anahtari[i] = 'E';
        }
    }
}

//OLUSTURULAN RASTGELE CEVAP ANAHTARININ YAZDIRILDIGI FONKSIYON
void cevap_anahtari_yazdir(char cevap_anahtari[], int S)
{
    printf(" CEVAP ANAHTARI:\n ");

    for(int i=0;i<S;i++)
    {
        printf("00%d: %c | ",i+1,cevap_anahtari[i]);
    }
        printf("\n\n");

}

//VERILEN OLASIKLAR ILE OLUSTURALAN SINAVA GIREN OGRENCILERIN SINAVI UYGULAMASI
//CEVAP ANAHTARI ILE OGRENCI CEVAPLARI KIYASLANIP DEGER DÝZÝLERE ATANIR
void sinavi_uygula(char ogrenci_cevaplari[ ][100], char cevap_anahtari[], int N, int S,double B,double D)
{
    srand(time(0));

    char cevaplar[6]={"ABCDE"};

      for(int i=0;i<N;i++)
      {
        for(int j=0;j<S;j++)
        {
         double c=(rand()%10)/10.0;  //c random sayi 0-1 arasi

           if(c>=0.0 && c<B)
           {
                ogrenci_cevaplari[j][i]='X';
           }
           else if(c>=B && c<B+D)
           {
               ogrenci_cevaplari[j][i]=cevap_anahtari[j];
           }
           else
           {
             if(cevap_anahtari[j]=='A')
              {
                while(1)
                 {
                   int indis = rand()%5;

                    if(indis==0)
                     {
                       ;
                     }
                    else
                    {
                        ogrenci_cevaplari[j][i] = cevaplar[indis];
                        break;
                    }
                 }
              }
                else if(cevap_anahtari[j]=='B')
                {
                  while(1)
                   {
                     int indis = rand()%5;

                      if(indis==1)
                       {
                          ;
                       }
                       else
                       {
                          ogrenci_cevaplari[j][i] = cevaplar[indis];
                          break;
                       }
                   }
                }
                  else if(cevap_anahtari[j]=='C')
                   {
                      while(1)
                       {
                         int indis = rand()%5;

                          if(indis==2)
                          {
                             ;
                          }
                          else
                           {
                            ogrenci_cevaplari[j][i] = cevaplar[indis];
                            break;
                           }
                       }
                   }
                  else if(cevap_anahtari[j]=='D')
                     {
                     while(1)
                       {
                          int indis = rand()%5;

                           if(indis==3)
                           {
                               ;
                           }
                           else
                           {
                               ogrenci_cevaplari[j][i] = cevaplar[indis];
                               break;
                           }
                       }
                    }
                   else
                    {
                        while(1)
                        {
                          int indis = rand()%5;

                          if(indis==4)
                          {
                            ;
                           }
                            else
                            {
                                ogrenci_cevaplari[j][i] = cevaplar[indis];
                                break;
                            }
                        }
                   }
               }
          }
      }
}

//OLASILIGI HESAPLANAN OGRENCI CEVABININ YAZDIRILDIGI FONKSIYON
void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[ ][100], int ogrenci_ID, int S)
{
    for(int i=0;i<ogrenci_ID;i++)
    {
      printf("00%d. ogrencinin cevaplari:\n",i+1);
      for(int j=0;j<S;j++)
       {
            printf("00%d:%c | ",j+1,ogrenci_cevaplari[j][i]);
       }
        printf("\n");
    }
}

//KENDI YAPTIGIMIZ HBN'NIN OLUSTUGU FONKSIYON
void ogrencileri_puanla(char ogrenci_cevaplari[][100],char cevap_anahtari[],double HBN[],int N,int S)
{
    for(int i=0;i<N;i++)
    {
        int dogru=0;
        float yanlis=0.0;
            for(int j=0;j<S;j++)
            {
                    if(cevap_anahtari[j]==ogrenci_cevaplari[j][i])
                {
                    dogru++;
                }
                    else if(cevap_anahtari[j]!=ogrenci_cevaplari[j][i] && ogrenci_cevaplari[j][i]!='X')
                {
                    yanlis++;
                }
                    else
                {
                    ;
                }
            }
    //HBN'NIN DIZIYE ATANDIGI BOLUM
    HBN[i]=(dogru-yanlis*0.25)*(100/S);

    }
// OGRENCI HBN'SI NEGATIF ISE 0 DEGERI ATANILAN DONGU
    for(int i=0;i<N;i++)
    {
        if(HBN[i]<0)
        {
            HBN[i]=0;
        }
        else
        {
            ;
        }
    }
}

//SINIF ORTALAMASININ HESAPLANDIGI FONKSIYON
double sinif_ortalamasi_hesapla(double HBN[ ], int N)
{
    float sinif_top=0;
    double n=N;
    float ortalama=0;

    for(int i=0;i<N;i++)
    {
        sinif_top +=HBN[i];
    }

    ortalama=sinif_top/n;

    return ortalama;
}

//STANDART SAPMANIN HESAPLANIGI FONKSIYON
double standart_sapma_hesapla(double ortalama, double HBN[ ], int N)
{
    int i;
    double std=0;

    for(i=0;i<N;i++)
    {
       (pow(HBN[i]-ortalama,2))/N;
    }
    std= sqrt((pow(HBN[i]-ortalama,2))/N);

    return std;
}

//T-SKORUNUN HER OGRENCI ICIN HESAPLANDIGI FONKSIYON
void T_skoru_hesapla(double ortalama, double HBN[ ], int N, double std, double T_skoru[ ])
{
    for(int i=0;i<N;i++)
    {
        T_skoru[i]=60+10*((HBN[i]-ortalama)/std);
    }
}

//SINIF DUZEYI OLUSTURDUGUMUZ FONKSIYON
void sinif_duzeyi(double ortalama,double HBN[],double std, int N)
{
    printf(" \n Sinif Ortalamasi : %.2lf , Standart Sapma : %.2lf \n",ortalama,std);

    if(ortalama<=100.0&& ortalama>80.0)
        printf(" Sinif Duzeyi : Ustun Basari \n");

    else if (ortalama<=80.0 && ortalama>70.0)
        printf(" Sinif Duzeyi : Mukemmel \n");

    else if (ortalama<=70.0 && ortalama>62.5)
        printf(" Sinif Duzeyi : Cok iyi \n");

    else if (ortalama<=62.50 && ortalama>57.50)
        printf(" Sinif Duzeyi : Iyi \n");

    else if (ortalama<=57.50 && ortalama>52.50)
        printf(" Sinif Duzeyi : Ortanin Ustu \n");

    else if (ortalama<=52.50 && ortalama>47.50)
        printf(" Sinif Duzeyi : Orta \n");

    else if (ortalama<=47.50 && ortalama>42.50)
        printf(" Sinif Duzeyi : Zayif \n");

    else if (ortalama<=42.50)
        printf(" Sinif Duzeyi : Kotu \n");

}


//OGRENCI ID , HBN ,T-SKORU VE HARF NOTUNUN VERILDIGI YER
void Ogrenci_notlari(double ortalama, double HBN[ ], int N, double std, double T_skoru[ ])
{

        printf("\n");

            for(int i=0;i<N;i++)
                {
                    if(ortalama<=100.0&& ortalama>80.0)//SINIF ORTALMASININ YERLLESTIGI YER
                      {
                                if(HBN[i]<32.00)//OGRENCILERIN HBN ' YE GORE YERLESTIGI YER
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FF",i+1,HBN[i],T_skoru[i]);
                            }
                                else if(HBN[i]>=32.00 && HBN[i]<=36.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=37.00 && HBN[i]<=41.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=42.00 && HBN[i]<=46.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=47.00 && HBN[i]<=51.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=52.00 && HBN[i]<=56.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=57.00 && HBN[i]<=61.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=62.00 && HBN[i]<=66.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BA",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=67.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: AA",i+1,HBN[i],T_skoru[i]);
                            }
                      }

                     else if (ortalama<=80.0 && ortalama>70.0)
                      {
                            if(HBN[i]<34.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FF",i+1,HBN[i],T_skoru[i]);
                            }
                                else if(HBN[i]>=34.00 && HBN[i]<=38.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=39.00 && HBN[i]<=43.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=44.00 && HBN[i]<=48.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=49.00 && HBN[i]<=53.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=54.00 && HBN[i]<=58.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=59.00 && HBN[i]<=63.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=64.00 && HBN[i]<=68.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BA",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=69.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: AA",i+1,HBN[i],T_skoru[i]);
                            }
                      }

                     else if (ortalama<=70.0 && ortalama>62.5)
                      {
                          if(HBN[i]<36.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FF",i+1,HBN[i],T_skoru[i]);
                            }
                                else if(HBN[i]>=36.00 && HBN[i]<=40.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=41.00 && HBN[i]<=45.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=46.00 && HBN[i]<=50.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=51.00 && HBN[i]<=55.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=56.00 && HBN[i]<=60.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=61.00 && HBN[i]<=65.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=66.00 && HBN[i]<=70.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BA",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=71.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: AA",i+1,HBN[i],T_skoru[i]);
                            }
                      }

                     else if (ortalama<=62.50 && ortalama>57.50)
                      {
                            if(HBN[i]<38.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FF",i+1,HBN[i],T_skoru[i]);
                            }
                                else if(HBN[i]>=48.00 && HBN[i]<=43.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=44.00 && HBN[i]<=47.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=48.00 && HBN[i]<=52.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=53.00 && HBN[i]<=57.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=58.00 && HBN[i]<=62.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=63.00 && HBN[i]<=67.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=68.00 && HBN[i]<=72.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BA",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=73.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: AA",i+1,HBN[i],T_skoru[i]);
                            }
                      }

                     else if (ortalama<=57.50 && ortalama>52.50)
                      {
                           if(HBN[i]<40.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FF",i+1,HBN[i],T_skoru[i]);
                            }
                                else if(HBN[i]>=40.00 && HBN[i]<=44.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=45.00 && HBN[i]<=49.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=50.00 && HBN[i]<=54.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=45.00 && HBN[i]<=59.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=60.00 && HBN[i]<=62.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=65.00 && HBN[i]<=69.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=70.00 && HBN[i]<=74.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BA",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=75.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: AA",i+1,HBN[i],T_skoru[i]);
                            }
                      }

                     else if (ortalama<=52.50 && ortalama>47.50)
                      {
                          if(HBN[i]<42.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FF",i+1,HBN[i],T_skoru[i]);
                            }
                                else if(HBN[i]>=42.00 && HBN[i]<=46.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=47.00 && HBN[i]<=51.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=52.00 && HBN[i]<=56.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=57.00 && HBN[i]<=61.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=62.00 && HBN[i]<=66.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=67.00 && HBN[i]<=71.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=72.00 && HBN[i]<=76.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BA",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=77.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: AA",i+1,HBN[i],T_skoru[i]);
                            }
                      }

                     else if (ortalama<=47.50 && ortalama>42.50)
                      {
                            if(HBN[i]<44.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FF",i+1,HBN[i],T_skoru[i]);
                            }
                                else if(HBN[i]>=44.00 && HBN[i]<=48.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=49.00 && HBN[i]<=53.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=54.00 && HBN[i]<=58.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=59.00 && HBN[i]<=63.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=64.00 && HBN[i]<=65.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=66.00 && HBN[i]<=70.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=71.00 && HBN[i]<=78.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BA",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=79.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: AA",i+1,HBN[i],T_skoru[i]);
                            }
                      }

                     else if (ortalama<=42.50)
                      {
                         if(HBN[i]<46.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FF",i+1,HBN[i],T_skoru[i]);
                            }
                                else if(HBN[i]>=46.00 && HBN[i]<=50.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: FD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=51.00 && HBN[i]<=55.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DD",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=56.00 && HBN[i]<=60.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: DC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=61.00 && HBN[i]<=65.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CC",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=66.00 && HBN[i]<=70.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: CB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=71.00 && HBN[i]<=75.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BB",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=76.00 && HBN[i]<=80.99 )
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: BA",i+1,HBN[i],T_skoru[i]);
                            }
                              else if(HBN[i]>=81.00)
                            {
                                printf("00%d. ogrencinin HBN: %.2lf , T-skoru: %.2lf ,harf notu: AA",i+1,HBN[i],T_skoru[i]);
                            }
                      }
                printf("\n");
            }
}




    int main()
{

    int N,S,ogrenci_ID;

    double B,D;
    double HBN[100];
    double T_skoru[100];
    double ortalama,std;

    char ogrenci_cevaplari[100][100];
    char cevap_anahtari[100];


    printf("Ogrenci Sayisini Giriniz(MAX 100): ");
    scanf("%d",&N);

    printf("Soru Sayisini Giriniz: ");
    scanf("%d",&S);

    printf("Bos Birakma Ihtimalini Giriniz: ");
    scanf("%lf",&B);

    printf("Dogru Cevap Verme Ihtimalini Giriniz: ");
    scanf("%lf",&D);


    cevap_anahtari_uret(cevap_anahtari,S);

    cevap_anahtari_yazdir(cevap_anahtari,S);

    sinavi_uygula(ogrenci_cevaplari,cevap_anahtari,N,S,B,D);

    ogrenci_cevabini_yazdir(ogrenci_cevaplari,N,S);

    ogrencileri_puanla(ogrenci_cevaplari,cevap_anahtari,HBN,N,S);

    ortalama =sinif_ortalamasi_hesapla(HBN,N);

    std=standart_sapma_hesapla(ortalama,HBN,N);

    T_skoru_hesapla(ortalama,HBN,N,std,T_skoru);

    sinif_duzeyi(ortalama,HBN,std,N);

    Ogrenci_notlari(ortalama,HBN,N,std,T_skoru);


    return 0;
}
