import os, subprocess
import time

#штука для обрезки кадра
def crop_image(imgg, json):
    img = Image.open("./key_frames/"+imgg)
    coords = json["faceRectangle"]
    top = coords["top"]
    left = coords["left"]
    end_top = top+coords["height"]
    end_left = left+ coords["width"]
    img_buff = img.crop((left-400, 0, end_left+400, img.size[1]))
    img_buff.save("./img_crop/crop-"+imgg, quality=95) 

#сабпроцесс для формирования ключевых кадров
subprocess.call(['./get_frames.sh movie.mp4'], shell=True)



di = './key_frames/'
list_key_frames = os.listdir(di)
ch = 1
for key_frame in list_key_frames:
    if(key_frame.split('-')[0] == 'keyframe'):
        #процесс для запроса к azure
        subprocess.call(['./get_face_from_key_frame.sh'+ ' ' + di+key_frame], shell=True)
        #print(key_frame)   
        #print(ch, '/',  len(list_key_frames))
        ch+=1
    #if(ch % (len(list_key_frames)-1) == 0):
     #   time.sleep(15)

#читаем из json файла
with open('json_faces.txt') as f:
    data = {}
    ch = 1
    json_line = ''
    for line in f:
        if ch == 1:
            print(line)
            json_line = line
            ch = 2
        elif ch == 2:
            data[line.split('/')[2].replace("\n", '')] = json_line
            ch = 1
#тут считываем из массива где ключ это название файла, значение - json
for key in data:
    try:
        print(json.loads(data[key].replace('\n', ''))[0])
        crop_image(key, json.loads(data[key].replace('\n',''))[0])
    except:
        print("fuck")

for key_frame in list_key_frames:
    img = cv2.imread("key_frames/"+ key_frame)


#сделать из картинок видео
subprocess.call(['./img_crop/toavi.sh'], shell=True)
