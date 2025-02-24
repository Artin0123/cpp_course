# 需先具備image.jpg為背景圖
# input.m4a為音檔
# 在同一個資料夾路徑下放入背景圖和音檔後執行

ffmpeg -loop 1 -i "image.jpg" -i "input.m4a" -c:a copy -c:v libx264 -shortest output.mp4
