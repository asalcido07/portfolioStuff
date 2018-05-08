from flask import Flask
app = Flask(__name__)

@app.route("/")
def hello():
    return "Hello World!"

# Do this to make this shit work

# set FLASK_APP=testwebapp.py
# flask run