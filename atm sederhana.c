#include <stdio.h>

float balance = 0;
int transaksi_lain;

void transaksi_lagi(){
    printf("\n\nIngin Melanjutkan Transaksi Lain?\nTekan 1 untuk melanjutkan atau 2 untuk keluar\n");
    scanf("%d", &transaksi_lain);
    if(transaksi_lain == 1){
        transaksi();
    }
}

void pass(){
    int sandi;

    printf("Masukkan Sandi : ");
    scanf("%d", &sandi);
}
void transaksi(){
    int pilihan;
    printf("\n===SIMPLE ATM===\n\n");
    printf("Selamat Datang!\n");
    printf("Masukkan Pilihan Anda\n\n");
    printf("1. Tarik Tunai\n");
    printf("2. Setor Tunai\n");
    printf("3. Cek Saldo\n\n");
    scanf("%d", &pilihan);

    switch(pilihan){
        int jumlah_tarik;
        int jumlah_setor;
        int yakin;

        case 1:
            printf("\n=TARIK TUNAI=\n\n");
            printf("Masukkan Nominal : ");
            scanf("%d", &jumlah_tarik);
            if(jumlah_tarik > balance){
                printf("\nSaldo Anda Tidak Cukup");
                transaksi_lagi();
            } else{
                printf("\nApakah Anda Yakin Nominal Yang Anda Masukkan Benar?\n");
                printf("Tekan 1 untuk melanjutkan dan 2 untuk mengulang\n");
                scanf("%d", &yakin);
                if (yakin == 1){
                    balance = balance - jumlah_tarik;
                    printf("------------------------------------------------------------------------");
                    printf("\nAnda telah menarik Rp.%d dan sisa saldo anda adalah Rp.%.2f", jumlah_tarik, balance);
                    printf("\n------------------------------------------------------------------------");
                    transaksi_lagi();
                } else{
                    transaksi();
                }

            }
        break;

        case 2:
            printf("\n=SETOR TUNAI=\n\n");
            printf("Masukkan Jumlah Setoran : ");
            scanf("%d", &jumlah_setor);
            printf("\nAnda akan melakukan setor tunai sebesar %d Rupiah\n", jumlah_setor);
            printf("Tekan 1 untuk melanjutkan dan 2 untuk mengulang\n");
            scanf("%d", &yakin);

            balance = jumlah_setor + balance;
            printf("----------------------------------------------");
            printf("\nJumlah Saldo Terkini = Rp.%.2f\n", balance);
            printf("----------------------------------------------");
            transaksi_lagi();

            break;

        case 3:
            printf("--------------------------------------");
            printf("\nJumlah Saldo Anda = Rp.%.2f\n", balance);
            printf("--------------------------------------");
            transaksi_lagi();

            break;
    }
}

int main()
{
    pass();
    transaksi();

    return 0;
}
