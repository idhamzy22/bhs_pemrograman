# Analisa Soal 3

## Graphical User Interface (GUI)
Graphical User Interface (GUI) adalah antarmuka pengguna yang memungkinkan pengguna untuk berinteraksi dengan program melalui elemen grafis seperti jendela, ikon, dan tombol. GUI lebih mudah digunakan dan lebih intuitif dibandingkan dengan antarmuka baris perintah (CLI). 

Dalam bahasa pemrograman Python, Tkinter adalah pustaka standar yang sering digunakan untuk membuat aplikasi GUI. Tkinter menyediakan berbagai widget yang dapat digunakan untuk membuat antarmuka pengguna, seperti:
- `Label`: Untuk menampilkan teks atau gambar.
- `Button`: Untuk membuat tombol yang dapat diklik.
- `Entry`: Untuk membuat kotak input teks.

## Contoh
Berikut adalah contoh implementasi sederhana GUI menggunakan Tkinter dalam Python.

### Contoh: Program GUI Sederhana dengan Tkinter
```python
import tkinter as tk

# Membuat instance dari Tkinter
root = tk.Tk()
root.title("Contoh GUI")

# Membuat label
label = tk.Label(root, text="Hello, World!")
label.pack()

# Membuat tombol
def on_button_click():
    label.config(text="Tombol diklik!")

button = tk.Button(root, text="Klik Saya", command=on_button_click)
button.pack()

# Menjalankan aplikasi
root.mainloop()
