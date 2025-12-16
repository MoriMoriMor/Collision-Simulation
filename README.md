📌 Simulasi Tumbukan Bola 2D Menggunakan Quadtree dan Brute Force (C++)
🧩 Deskripsi Proyek

Proyek ini merupakan simulasi grafis tumbukan bola 2D menggunakan bahasa C++ dengan library graphics.h.
Tujuan utama dari program ini adalah membandingkan performa dan konsep collision detection antara dua pendekatan:

Brute Force Collision Detection

Quadtree-Based Collision Detection

Simulasi menampilkan ribuan bola yang bergerak secara acak dan saling bertumbukan di dalam jendela grafis secara real-time.

🎯 Tujuan

Mengimplementasikan simulasi fisika sederhana (gerak dan tumbukan).

Mempelajari efisiensi algoritma Brute Force vs Quadtree.

Menampilkan perbandingan metode collision detection secara interaktif.

Mengoptimalkan deteksi tumbukan pada jumlah objek yang besar.

🛠️ Teknologi dan Library

Bahasa: C++

Library Grafis:

graphics.h

conio.h

Library Standar:

<stdlib.h>

<time.h>

<math.h>

⚠️ Catatan: Program ini dijalankan menggunakan WinBGIm / BGI Graphics (umumnya pada compiler seperti Dev-C++ atau Code::Blocks).

⚙️ Fitur Program

Menampilkan 4504 bola bergerak secara acak.

Simulasi tumbukan elastis antar bola.

Dua mode collision detection:

Brute Force

Quadtree

Mode Pause / Resume simulasi.

Double buffering untuk animasi lebih halus.

Pergantian mode secara real-time melalui keyboard.

🎮 Kontrol Keyboard
Tombol	Fungsi
W	Mode Brute Force Collision
Q	Mode Quadtree Collision
Space	Pause / Resume simulasi
Esc	Keluar dari program
🧠 Penjelasan Konsep
1️⃣ Brute Force Collision Detection

Metode ini memeriksa setiap pasangan bola untuk mendeteksi tumbukan.

Kompleksitas Waktu:

𝑂
(
𝑛
2
)
O(n
2
)

Kelebihan:

Mudah diimplementasikan

Akurat untuk jumlah objek kecil

Kekurangan:

Sangat lambat untuk jumlah objek besar

2️⃣ Quadtree Collision Detection

Quadtree membagi ruang 2D menjadi beberapa area (node) untuk mengurangi jumlah pengecekan tumbukan.

Cara Kerja:

Ruang dibagi menjadi 4 bagian (NW, NE, SW, SE)

Bola disimpan sesuai lokasi

Tumbukan hanya dicek dengan objek di area yang sama

Kelebihan:

Lebih cepat dan efisien

Cocok untuk simulasi skala besar

Kekurangan:

Implementasi lebih kompleks

Membutuhkan manajemen memori tambahan

🧱 Struktur Program
🔹 Class Ball

Merepresentasikan objek bola dengan atribut:

Posisi (x, y)

Kecepatan (dx, dy)

Radius (r)

Warna (color)

Fungsi utama:

move() → Menggerakkan bola dan memantul di dinding

draw() → Menggambar bola

collide() → Menangani tumbukan antar bola

🔹 Class Quadtree

Digunakan untuk optimasi collision detection.

Atribut utama:

Area (x, y, w, h)

Kapasitas node

Child node (nw, ne, sw, se)

Penyimpanan objek bola

Fungsi utama:

insert() → Menyimpan bola ke node yang sesuai

subdivide() → Membagi node ketika kapasitas penuh

contains() → Mengecek apakah bola berada di area node

🧪 Alur Program

Inisialisasi window grafis

Membuat ribuan objek bola secara acak

Loop utama:

Input keyboard

Update posisi bola

Deteksi tumbukan (sesuai mode)

Gambar bola ke layar

Program berjalan hingga Esc ditekan

📊 Hasil Pengujian

Brute Force: Terjadi penurunan FPS drastis saat jumlah bola besar

Quadtree: Simulasi jauh lebih stabil dan responsif

Kesimpulan: Quadtree jauh lebih efisien untuk collision detection skala besar

📌 Kesimpulan

Proyek ini menunjukkan bahwa penggunaan struktur data spasial seperti Quadtree sangat efektif dalam meningkatkan performa simulasi grafis, terutama ketika jumlah objek sangat banyak. Implementasi ini cocok sebagai studi kasus optimasi algoritma dalam simulasi fisika dan game development.
