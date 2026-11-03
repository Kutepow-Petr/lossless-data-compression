from PIL import Image
import os
import sys

if getattr(sys, 'frozen', False):
    BASE_DIR = os.path.dirname(sys.executable)
else:
    BASE_DIR = os.path.dirname(os.path.abspath(__file__))
img_path = input('Image path: ').strip('\'"')

img = Image.open(img_path)
img_name = os.path.splitext(os.path.basename(img_path))[0]
def get_save_path(suffix):
    return os.path.join(BASE_DIR, f"{img_name}_{suffix}.raw")

# Для 3 байт на пиксель
rgb_img = img.convert('RGB')
with open(get_save_path('rgb'), 'wb') as f:
    f.write(rgb_img.tobytes())
rgb_img.show()

# Для 1 байта на пиксель
gray_img = img.convert('L')
with open(get_save_path('gray'), 'wb') as f:
    f.write(gray_img.tobytes())
gray_img.show()

# Для 1 бита на пиксель
black_img = img.convert('1')
with open(get_save_path('black'), 'wb') as f:
    f.write(black_img.tobytes())
black_img.show()