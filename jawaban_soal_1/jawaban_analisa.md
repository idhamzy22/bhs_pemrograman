# Analisa Soal 1

## Function
Fungsi dalam Python adalah blok kode yang dirancang untuk melakukan tugas tertentu. Fungsi bisa menerima input dalam bentuk parameter dan bisa mengembalikan hasil output. Berikut adalah struktur dasar dari sebuah fungsi:
```python
def nama_fungsi(parameter1, parameter2):
    # blok kode
    return hasil


kita bisa memanggil fungsi ini dengan cara berikut:

nama_fungsi(argumen1, argumen2)



Recursive Function
Recursive function adalah fungsi yang memanggil dirinya sendiri untuk menyelesaikan masalah yang lebih kecil dari masalah aslinya. Contoh klasik dari penggunaan rekursi adalah perhitungan faktorial dari sebuah angka:

def faktorial(n):
    if n == 0:
        return 1
    else:
        return n * faktorial(n-1)

Dalam contoh ini, `faktorial` adalah fungsi rekursif yang terus memanggil dirinya sendiri dengan nilai yang lebih kecil hingga mencapai nilai dasar (n == 0).



Contoh
Berikut adalah contoh implementasi fungsi dan recursive function dalam Python.


Function

def tambah(a, b):
    return a + b

hasil = tambah(3, 5)
print(hasil)  # Output: 8


Recursive Function

def faktorial(n):
    if n == 0:
        return 1
    else:
        return n * faktorial(n-1)

hasil = faktorial(5)
print(hasil)  # Output: 120