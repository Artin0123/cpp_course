set input=.avi
set output=.wav
for %%f in (*%input%) do (
		ffmpeg -i "%%~nf%input%" -c copy "%%~nf%output%"
)