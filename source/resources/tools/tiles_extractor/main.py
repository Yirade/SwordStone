import os
from PIL import Image

def extract_tiles(file_path, tile_width, tile_height, pixel_distance, output_dir):
    # Carica l'immagine
    image = Image.open(file_path)

    # Ottieni le dimensioni dell'immagine
    image_width, image_height = image.size

    # Calcola il numero di tile orizzontali e verticali
    num_horizontal_tiles = (image_width - tile_width) // (tile_width + pixel_distance) + 1
    num_vertical_tiles = (image_height - tile_height) // (tile_height + pixel_distance) + 1

    # Crea la directory di output se non esiste
    os.makedirs(output_dir, exist_ok=True)

    # Estrai i tile
    for y in range(num_vertical_tiles):
        for x in range(num_horizontal_tiles):
            # Calcola le coordinate del tile nella posizione corrente
            tile_x = x * (tile_width + pixel_distance)
            tile_y = y * (tile_height + pixel_distance)

            # Estrai il tile come immagine separata
            tile_image = image.crop((tile_x, tile_y, tile_x + tile_width, tile_y + tile_height))

            # Salva il tile su file nella directory di output
            tile_filename = os.path.join(output_dir, f"tile_{y * num_horizontal_tiles + x}.png")
            tile_image.save(tile_filename)

# Directory di input e output
input_dir = "INPUT"
output_dir = "OUTPUT"

# Richiedi all'utente i parametri di dimensione dei tile e distanza tra di essi
tile_width = int(input("Inserisci la larghezza dei tile: "))
tile_height = int(input("Inserisci l'altezza dei tile: "))
pixel_distance = int(input("Inserisci la distanza in pixel tra i tile: "))

# Ottieni i file di input dalla directory di input
input_files = [os.path.join(input_dir, file) for file in os.listdir(input_dir) if file.endswith(".png")]

# Esegui l'estrazione dei tile per ogni file di input
for input_file in input_files:
    # Ottieni il nome del file di input senza l'estensione
    file_name = os.path.splitext(os.path.basename(input_file))[0]

    # Crea la directory di output specifica per il file di input
    output_subdir = os.path.join(output_dir, file_name)
    os.makedirs(output_subdir, exist_ok=True)

    # Esegui l'estrazione dei tile per il file di input corrente
    extract_tiles(input_file, tile_width, tile_height, pixel_distance, output_subdir)

