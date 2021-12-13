#include "kaHeader.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
  // inisialisasi struct yang dibutuhkan untuk membuat node kereta api
  int pilihan_menuAwal, pilih_ka, pilih_kelas, pesan_jumlah_tiket, sistemTiket;

  KA *kereta_api1 = (KA *)malloc(sizeof(KA) * 1);
  KA *kereta_api2 = (KA *)malloc(sizeof(KA) * 1);
  KA *kereta_api3 = (KA *)malloc(sizeof(KA) * 1);

  kereta_api1->kode_kereta = 1;
  strcpy(kereta_api1->namaKeretaApi, "Cruise Train Seven Stars");
  strcpy(kereta_api1->destinasi, "Palembang - Jakarta");
  strcpy(kereta_api1->jam_keberangkatan, "14.25 WIB");
  strcpy(kereta_api1->jenis_kelas, "Eksekutif | Bisnis | Biasa");
  kereta_api1->daya_tampung = 150;
  kereta_api1->sisa_tiket = 150;
  kereta_api1->kelas_eksekutif = 30;
  kereta_api1->harga_eksekutif = 175000;
  kereta_api1->kelas_bisnis = 40;
  kereta_api1->harga_bisnis = 110000;
  kereta_api1->kelas_biasa = 80;
  kereta_api1->harga_biasa = 65000;
  kereta_api1->id_eksekutif = 1;
  kereta_api1->id_bisnis = 2;
  kereta_api1->id_biasa = 3;
  kereta_api1->keuntungan_kereta = 0;
  kereta_api1->nextNode = kereta_api2;

  kereta_api2->kode_kereta = 2;
  strcpy(kereta_api2->namaKeretaApi, "Venice Simplon-Orient-Express");
  strcpy(kereta_api2->destinasi, "Medan - Denpasar");
  strcpy(kereta_api2->jam_keberangkatan, "19.00 WITA");
  strcpy(kereta_api2->jenis_kelas, "Eksekutif | Bisnis | Biasa");
  kereta_api2->daya_tampung = 125;
  kereta_api2->sisa_tiket = 125;
  kereta_api2->kelas_eksekutif = 25;
  kereta_api2->harga_eksekutif = 160000;
  kereta_api2->kelas_bisnis = 40;
  kereta_api2->harga_bisnis = 100000;
  kereta_api2->kelas_biasa = 60;
  kereta_api2->harga_biasa = 60000;
  kereta_api2->id_eksekutif = 1;
  kereta_api2->id_bisnis = 2;
  kereta_api2->id_biasa = 3;
  kereta_api2->keuntungan_kereta = 0;
  kereta_api2->nextNode = kereta_api3;

  kereta_api3->kode_kereta = 3;
  strcpy(kereta_api3->namaKeretaApi, "Maharajas Express");
  strcpy(kereta_api3->destinasi, "Makassar - Pontianak");
  strcpy(kereta_api3->jam_keberangkatan, "8.45 WITA");
  strcpy(kereta_api3->jenis_kelas, "Eksekutif | Bisnis | Biasa");
  kereta_api3->daya_tampung = 90;
  kereta_api3->sisa_tiket = 90;
  kereta_api3->kelas_eksekutif = 15;
  kereta_api3->harga_eksekutif = 140000;
  kereta_api3->kelas_bisnis = 25;
  kereta_api3->harga_bisnis = 105000;
  kereta_api3->kelas_biasa = 50;
  kereta_api3->harga_biasa = 70000;
  kereta_api3->id_eksekutif = 1;
  kereta_api3->id_bisnis = 2;
  kereta_api3->id_biasa = 3;
  kereta_api3->keuntungan_kereta = 0;
  kereta_api3->nextNode = NULL;

  // variable penampung yang bersifat constant untuk data size kelas
  int const sz_eksekutif1 = kereta_api1->kelas_eksekutif;
  int const sz_bisnis1 = kereta_api1->kelas_bisnis;
  int const sz_biasa1 = kereta_api1->kelas_biasa;
  int const sz_eksekutif2 = kereta_api2->kelas_eksekutif;
  int const sz_bisnis2 = kereta_api2->kelas_bisnis;
  int const sz_biasa2 = kereta_api2->kelas_biasa;
  int const sz_eksekutif3 = kereta_api3->kelas_eksekutif;
  int const sz_bisnis3 = kereta_api3->kelas_bisnis;
  int const sz_biasa3 = kereta_api3->kelas_biasa;

  // variable penampung yang bersifat constant untuk data harga tiket
  int const harga_eksekutif1 = kereta_api1->harga_eksekutif;
  int const harga_bisnis1 = kereta_api1->harga_bisnis;
  int const harga_biasa1 = kereta_api1->harga_biasa;
  int const harga_eksekutif2 = kereta_api2->harga_eksekutif;
  int const harga_bisnis2 = kereta_api2->harga_bisnis;
  int const harga_biasa2 = kereta_api2->harga_biasa;
  int const harga_eksekutif3 = kereta_api3->harga_eksekutif;
  int const harga_bisnis3 = kereta_api3->harga_bisnis;
  int const harga_biasa3 = kereta_api3->harga_biasa;

// menu awal
menu_awal:
  printf("======Kereta Api Ku======\n");
  printf("[1] Informasi Kereta Api\n");
  printf("[2] Beli Tiket\n");
  printf("[3] Keuntungan Kereta Api Ku\n");
  printf("[4] Keluar\n");
  printf("\nPilih : ");
  scanf("%d", &pilihan_menuAwal);

  switch (pilihan_menuAwal) {
    // case 1 digunakan untuk menampilkan informasi detail mengenai kereta api
  case 1:
    cetakInformasi(kereta_api1);
    goto menu_awal;

    // case 2 digunakan untuk menampilkan list kereta api yang ingin dipilih
    // untuk membeli tiket
  case 2:
  backTiket:
    daftarKa(kereta_api1);

  backKereta:
    printf("\nPilih Kereta : ");
    scanf("%d", &pilih_ka);
    if (pilih_ka > 3) {
      printf("\nInputan yang anda masukkan salah!\n");
      goto backKereta;
    }

    // prosedur yang digunakan untuk menghitung harga tiket naik 20%
    hargaNaik(kereta_api1, sz_eksekutif1, sz_bisnis1, sz_biasa1, sz_eksekutif2,
              sz_bisnis2, sz_biasa2, sz_eksekutif3, sz_bisnis3, sz_biasa3,
              harga_eksekutif1, harga_bisnis1, harga_biasa1, harga_eksekutif2,
              harga_bisnis2, harga_biasa2, harga_eksekutif3, harga_bisnis3,
              harga_biasa3, pilih_ka);

    // prosedur untuk memilih kereta api
    pilihanKa(kereta_api1, pilih_ka, pesan_jumlah_tiket);

    printf("\nPilih Kelas\t: ");
    scanf("%d", &pilih_kelas);

    printf("Jumlah Tiket\t: ");
    scanf("%d", &pesan_jumlah_tiket);

    // prosedur yang digunakan untuk menghitung keuntungan masing masing kereta
    hitungKeuntungan(kereta_api1, pilih_ka, pilih_kelas, pesan_jumlah_tiket);

    // fungsi operasi pembelian tiket yang mengembalikan nilai boolean
    sistemTiket =
        operasitiket(kereta_api1, pilih_kelas, pesan_jumlah_tiket, pilih_ka);

    if (sistemTiket == 1) {
      system("cls");
      printf("----%d tiket pesanan dibeli [Pembelian "
             "Berhasil]----\n",
             pesan_jumlah_tiket);
    } else if (sistemTiket == 0) {
      system("cls");
      printf("----Tiket pesanan tidak sesuai [Pembelian Gagal]----\n\n");
    }

    goto menu_awal;

    // case 3 digunakan untuk mencetak keuntungan dari total dan masing masing kereta
  case 3:
    cetakKeuntungan(kereta_api1);
    goto menu_awal;

    // case 4 = exit
  case 4:
    system("cls");
    printf("~Terima kasih sudah menggunakan aplikasi Kereta Api Ku~\n");
    exit(1);

  default:
    printf("Keywords yang anda masukkan salah!\n");
    goto menu_awal;
  }

  return 0;
}