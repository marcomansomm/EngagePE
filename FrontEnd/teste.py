from flask import Flask, render_template
app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/home")
def home():
    return render_template("home.html")

@app.route("/noticias")
def noticias():
    return render_template("noticias.html")

@app.route("/news1")
def news1():
    return render_template("news1.html")

@app.route("/news2")
def news2():
    return render_template("news2.html")

@app.route("/programacao")
def programacao():
    return render_template("programacao.html")

@app.route("/login_cadastro")
def login_cadastro():
    return "login cadastro"

@app.route("/qrcode")
def qrcode():
    return render_template("qrcode.html")

@app.route("/figurinhas")
def figurinhas():
    return render_template("figurinhas.html")

if __name__ == "__main__":
    app.run(debug=True)