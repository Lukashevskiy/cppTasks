
videofile=$1


ffmpeg -i $videofile -vf select='eq(pict_type\,I)' -vsync 2 -s 1920*1080 -f image2 ./key_frames/keyframe-%d.jpeg -v error

ffprobe -v error -i $videofile -select_streams v -show_frames -show_entries frame=pict_type -of csv | grep -n I | cut -d ':' -f 1 > ./key_frames/frame_index.txt 

