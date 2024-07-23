# Analisa Soal 2

## Exception Handling
Exception handling dalam Python adalah mekanisme untuk menangani kesalahan runtime yang terjadi saat eksekusi program. Kesalahan ini bisa berupa kesalahan sintaks, kesalahan logika, atau kesalahan runtime lainnya. Dengan exception handling, kita bisa menangani kesalahan ini dengan cara yang lebih terstruktur dan mencegah program dari crash. 

Berikut adalah struktur dasar exception handling dalam Python:
```python
try:
    # kode yang mungkin menghasilkan pengecualian
except TipePengecualian:
    # kode untuk menangani pengecualian
else:
    # kode yang dijalankan jika tidak ada pengecualian
finally:
    # kode yang selalu dijalankan
