Simulasi Partikel

Program ini mensimulasikan sekumpulan partikel (bola) berwarna-warni yang bergerak secara acak di dalam layar. Partikel-partikel tersebut dapat saling bertumbukan dan memantul satu sama lain dengan menerapkan hukum fisika dasar.

Fokus utama dari proyek ini adalah kemampuan untuk beralih secara real-time antara dua metode deteksi tabrakan yang berbeda, sehingga pengguna dapat membandingkan performa sistem berdasarkan nilai FPS (Frames Per Second).

Tools & Technologies

Bahasa Pemrograman: C++

Library Grafis: gprahic.h

Version Control: Git

Metode Pelaporan: README.md

Fitur Utama
Perbandingan Algoritma Deteksi Tabrakan

Program mendukung dua mode deteksi tabrakan yang dapat dipilih pengguna:

Brute Force (O(N²))
Metode sederhana yang membandingkan setiap partikel dengan semua partikel lainnya.
Digunakan sebagai patokan untuk memahami kompleksitas dan performa dasar.

Quadtree (O(N log N))
Menggunakan struktur data spasial hierarkis (Quadtree) untuk mengurangi jumlah pemeriksaan tabrakan.
Metode ini meningkatkan performa secara signifikan ketika jumlah partikel besar.

Interaktivitas & Debugging Real-Time

Fitur interaktif untuk pengujian dan analisis performa:

Mode Switcher (Tombol TAB)
Tekan tombol TAB untuk beralih secara langsung antara mode BRUTE FORCE dan QUADTREE.

FPS Tracker
Menampilkan nilai Frames Per Second (FPS) secara real-time di sudut kiri atas layar.
Digunakan untuk membandingkan performa kedua metode deteksi tabrakan.

Indikator Mode & Jumlah Partikel
Informasi teks di layar menampilkan:

Mode deteksi tabrakan yang sedang aktif

Jumlah partikel dalam simulasi

Dinamika Partikel

<img width="1492" height="809" alt="Screenshot 2025-12-16 230902" src="https://github.com/user-attachments/assets/01f7e437-5b1e-4086-a77b-9f1d7c1f5167" />


Spawn On Click
Klik di mana saja pada layar untuk menambahkan partikel baru.

Ukuran & Kecepatan Bervariasi
Setiap partikel memiliki radius, massa, dan kecepatan awal yang berbeda untuk menciptakan simulasi yang dinamis.
