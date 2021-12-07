import sys, json
from PIL import Image, ImageDraw
img = Image.open('./img.jpg').convert("RGBA")
imgDraw = ImageDraw.Draw(img)   
json = json.load(sys.stdin)
for el in json:
    coords = el["faceRectangle"]
    top = coords["top"]
    left = coords["left"]
    end_top = top+coords["height"]
    end_left = left+ coords["width"]
    img_buff = img.crop((left, top, end_left, end_top))
    img_buff.save(el["faceId"]+"-fragment.png", quality=95) 
    imgDraw.rectangle(((left, top),(end_left, end_top)), outline=(0, 0, 0))
    
img.save("face_img", "PNG")



