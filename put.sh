echo uart port
read com_port

ampy --port $com_port put ./uPy/main.py
echo put main on board
ampy --port $com_port put ./uPy/__init__.py
echo put __init__ on board
ampy --port $com_port put ./uPy/gps.py
echo put gps on board
ampy --port $com_port put ./uPy/encry.py
echo put encry on board
ampy --port $com_port put ./uPy/logging.py
echo put logging on board
ampy --port $com_port put ./uPy/post.py
echo put post on board
ampy --port $com_port put ./uPy/reqst.py
echo put reqst on board