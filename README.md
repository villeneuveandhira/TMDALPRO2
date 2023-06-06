# TMDALPRO2
Saya [Villeneuve Andhira Suwandhi] mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah<br />
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak<br />
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.<br />

# DBMS Koreksian
Materi yang digunakan: Mesin Kata dan Sequential File<br />
Buatlah sebuah program DBMS Koreksian dengan spesifikasi berikut:<br />
<br />
Buat 2 atau 3 buah arsip beruntun yang silakan didesain sendiri, untuk menjadi tabel<br />
(setiap mahasiswa tidak boleh memiliki desain yang sama satu sama lain untuk tabel, dan<br />
contoh di deskripsi TMD ini juga tidak boleh digunakan), misalnya<br />
<br />
  file tmahasiswa yang berisi NIM berupa string, nama berupa string (NIM<br />
  dianggap sebagai primary key jadi tidak boleh ada kode yang sama di file)<br />
  - silakan didesain sendiri, ini hanya contoh, jangan dipergunakan.<br />
<br />
DBMS dapat melakukan:<br />
1. Memproses per kata pada query masukan user dengan menggunakan mesin kata<br />
2. Query silakan didesain sendiri dengan spesifikasi (boleh dimodifikasi namun
sebisa mungkin mudah dimengerti):<br />
  &nbsp;a. Kata query awal yang diperbolehkan adalah ENTRI, UBAH, HAPUS,<br />
        TAMPIL diikuti dengan nama tabel, kemudian data (kecuali TAMPIL)<br />
        dan tanda akhir query sebagai EOP yaitu ; (titik koma). Urutan data sesuai<br />
        dengan urutan kolom tabel di sequential file. Misalkan.<br />
        <br />
  &nbsp;ENTRI UBAH tmahasiswa 13501058 Rosa;<br />
        <br />
  &nbsp;b. query merupakan pita mesin kata. Jadi pemrosesannya menggunakan<br />
        mesin kata untuk memahami maksud query. Dari query di atas maka<br />
        artinya jika data belum ada maka lakukan ENTRI jika data ada maka<br />
        lakukan UBAH. 13501058 adalah nilai kolom NIM, dan Rosa adalah nilai<br />
        kolom Nama. Jika perintah hanya ENTRI saja maka perintahnya pasti<br />
        hanya memasukkan data jika belum ada. Jadi perintah depan bisa 1 atau 2.<br />
        Tampilkan ke layar query yang dijalankan jika terdapat perintah lebih dari<br />
        satu, atau jika query tidak bisa dijalankan.<br />
  &nbsp;c. desain query harus jelas dimengerti.<br />
<br />
(Jangan lupa tes juga dengan kasus salah, misalnya jika kolom hanya 2 tapi
masukan nilai ada 3, dst)
<br />
<br />
Tampilan awal program:<br />
<br />
misalkan tampilan awal sebagai berikut:<br 
                                           
![image](https://github.com/villeneuveandhira/TMDALPRO2/assets/101118033/0d8ee3ec-cbad-4f6f-bea0-e13762f50405)

misal<br />
![image](https://github.com/villeneuveandhira/TMDALPRO2/assets/101118033/227b91ed-bfbb-433e-8bf7-8e12ceb26afb)

lalu menunggu masukan query<br />
![image](https://github.com/villeneuveandhira/TMDALPRO2/assets/101118033/495e3b59-1e7e-4927-8bf8-54b555a99bd9)

menunggu masukan lagi sebagai pita.<br />
Contoh-contoh query berikutnya:<br />
Jika data yang akan dioperasikan sesuai query belum ada<br /><br />
![image](https://github.com/villeneuveandhira/TMDALPRO2/assets/101118033/e2298925-1b75-4eb0-9497-5130195a8701)

Jika data yang akan dioperasikan ada<br />
![image](https://github.com/villeneuveandhira/TMDALPRO2/assets/101118033/13d21669-bbae-4c2a-a9db-c5b8d27889a5)

Jika data yang akan dioperasikan ada<br />
![image](https://github.com/villeneuveandhira/TMDALPRO2/assets/101118033/6d0c64de-3779-4f6d-be18-03efb251d766)


3. TAMPIL dengan query TAMPIL NamaTabel.<br />
Misal query nya sebagai berikut:<br />
<br />
TAMPIL tmahasiswa.
<br />
query merupakan pita mesin kata. Jadi pemrosesannya menggunakan mesin kata<br />
untuk memahami maksud query. Dari query di atas maka tampilkan isi tabel<br />
dalam arsip beruntun. Misal sebagai berikut:<br />
![image](https://github.com/villeneuveandhira/TMDALPRO2/assets/101118033/4490f64b-7046-4164-be04-b2d3d402435a)
menunggu masukan lagi sebagai pita.<br />
<br />
Jika menerima pita berisi<br />
<br />
jangan lupa bahagia hari ini;<br />
<br />
maka jalankan system("exit") atau keluar dari aplikasi.<br />
<br />
Pesan yang ditampilkan dapat didefinisikan sendiri, misalnya<br />
Hore Berhasil<br />
Hidup Persib<br />
Go Barca Go<br />
dkk :D.<br />
<br />
Yang penting bisa dimengerti dan masih dalam batas yaaaaaa…. ga kasar lah ☺ .<br />
<br />
Silakan membuat asumsi-asumsi sendiri untuk kreatifitas untuk proses-proses yang<br />
belum dijelaskan dalam deskripsi TMD ini, dan jangan lupa untuk dipresentasikan<br />
pada video presentasi.<br />
<br />
<br />
<br />
Bonus Nilai 20<br />
Bonus (Diberikan jika spesifikasi utama tugas individu di atas telah dipenuhi):<br />
Mampu menerima query join tabel yang memiliki primary key dari foreign key. Misalkan
sebagai berikut:
![image](https://github.com/villeneuveandhira/TMDALPRO2/assets/101118033/223be527-0a34-494f-adda-58556df82a0d)
