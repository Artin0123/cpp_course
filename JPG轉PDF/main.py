from PIL import Image
import os

dir_path = os.path.dirname(os.path.realpath(__file__))

images = [
		Image.open(dir_path + '/' + f)
		for f in ["P_20240603_225729.jpg"]
]

pdf_path = os.path.join(dir_path, "output.pdf")

images[0].save(
		pdf_path, "PDF" ,resolution=100.0, save_all=True, append_images=images[1:]
)