set input=.wav
set output=.aac
for %%f in (*%input%) do (
		ffmpeg -i "%%~nf%input%" -c:a aac "%%~nf%output%"
)