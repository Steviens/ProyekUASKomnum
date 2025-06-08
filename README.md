# Numerical Modeling of Temperature Dynamics 
###### Stevie Nathania Siregar-2306242382

---

**Deskripsi Proyek**  
Proyek ini merupakan implementasi metode numerik Euler untuk mensimulasikan penurunan suhu secangkir kopi panas berdasarkan hukum Newton tentang pendinginan. Simulasi dilakukan dengan bahasa pemrograman C dan menghasilkan data suhu terhadap waktu yang divisualisasikan melalui grafik.

---

## Hasil dan Analisis
![Image](https://github.com/user-attachments/assets/11e3936e-b584-4506-9ede-7d5bd64ca4a6)
Program simulasi yang dikembangkan dengan metode Euler berhasil menggambarkan dinamika penurunan suhu kopi dari waktu ke waktu secara numerik. Berdasarkan hasil simulasi dengan variasi langkah waktu, diperoleh bahwa akurasi metode ini sangat bergantung pada besarnya interval waktu yang digunakan.

Pada langkah waktu yang lebih besar, seperti Δt = 20 detik, perbedaan antara hasil simulasi dan solusi eksak menjadi cukup mencolok, terutama mendekati akhir periode pengamatan. Hal ini ditunjukkan oleh grafik yang memperlihatkan penyimpangan kurva Euler dari bentuk eksponensial ideal. Nilai error absolut cenderung meningkat seiring waktu, mencerminkan akumulasi kesalahan khas dari pendekatan Euler dengan interval besar.

Sebaliknya, saat digunakan langkah waktu yang lebih kecil seperti Δt=5 detik, hasil simulasi menjadi jauh lebih presisi. Kurva numerik hampir seluruhnya berimpit dengan solusi eksak, dan error maksimum tercatat sangat kecil, umumnya di bawah 0,2°C. Hal ini membuktikan bahwa metode Euler dapat memberikan hasil yang memadai untuk kasus sederhana, asalkan parameter numeriknya dipilih dengan cermat.

Secara fisis, hasil simulasi juga konsisten dengan teori. Suhu kopi menurun secara bertahap menuju suhu lingkungan (25°C) mengikuti kurva eksponensial, sesuai dengan prediksi hukum Newton. Dengan demikian, metode Euler terbukti mampu digunakan secara efektif dalam memodelkan fenomena pendinginan sebagai pendekatan numerik terhadap persamaan diferensial orde satu.



