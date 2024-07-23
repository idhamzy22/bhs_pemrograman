# Function
def tambah(a, b):
    return a + b

hasil_tambah = tambah(3, 5)
print("Hasil tambah:", hasil_tambah)  # Output: 8

# Recursive Function
def faktorial(n):
    if n == 0:
        return 1
    else:
        return n * faktorial(n-1)

hasil_faktorial = faktorial(5)
print("Hasil faktorial:", hasil_faktorial)  # Output: 120
