# Contoh 1: Menangani kesalahan pembagian dengan nol
try:
    hasil = 10 / 0
except ZeroDivisionError:
    print("Error: Pembagian dengan nol tidak diperbolehkan.")

# Contoh 2: Menangani kesalahan tipe data
try:
    hasil = 10 + "5"
except TypeError:
    print("Error: Operasi tidak valid antara tipe data yang berbeda.")

# Contoh 3: Menggunakan blok else dan finally
try:
    hasil = 10 / 2
except ZeroDivisionError:
    print("Error: Pembagian dengan nol tidak diperbolehkan.")
else:
    print("Hasil:", hasil)
finally:
    print("Blok finally selalu dijalankan.")
