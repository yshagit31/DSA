import cv2
import os
import argparse

def show_file_size(file):
    file_size = os.path.getsize(file)
    file_size_mb = round(file_size / (1024 * 1024), 2)
    print(f"File size is now {file_size_mb} MB")

if __name__ == "_main_":
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--image", required=True, help="Path to input file")
    ap.add_argument("-c", "--compression", required=True, help="Compression level", type=int)
    args = vars(ap.parse_args())

    image = cv2.imread(args["image"])

    if image is None:
        print(f"Error: Unable to read the image file '{args['image']}'")
        exit(1)

    output_file = "compressed_image.jpg"
    cv2.imwrite(output_file, image, [cv2.IMWRITE_JPEG_QUALITY, args["compression"]])

    print("Image Compressed Successfully")
    show_file_size(output_file)