@echo off
python plus_minus.py < input > myOut
fc myOut expected > NUL
if %errorlevel%==0 (
    echo "Correct"
) else (
    echo "IN-correct"
)

