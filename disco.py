import os

def list_files_and_sizes(start_path):
    # Recorrer directorios y archivos desde el directorio inicial
    for dirpath, dirnames, filenames in os.walk(start_path):
        for filename in filenames:
            # Obtener la ruta completa del archivo
            file_path = os.path.join(dirpath, filename)
            try:
                # Obtener el tamaño del archivo
                file_size = os.path.getsize(file_path)
                print(f"Archivo: {file_path}, Tamaño: {file_size} bytes")
            except OSError as e:
                print(f"Error al obtener el tamaño del archivo: {file_path}, {e}")

if __name__ == "__main__":
    # Directorio que se desea recorrer
    start_directory = input("Ingrese el directorio a recorrer: ")
    list_files_and_sizes(start_directory)
