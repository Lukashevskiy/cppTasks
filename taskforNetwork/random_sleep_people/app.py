from flask import Flask, render_template
import random

app = Flask(__name__)


images = [ "https://www.boredpanda.com/blog/wp-content/uploads/2021/05/25-609ce6b3452ca__700.jpg",
        "https://www.boredpanda.com/blog/wp-content/uploads/2021/05/45-609d32dd894be__700.jpg",
        "https://www.boredpanda.com/blog/wp-content/uploads/2021/05/3-609ba8061b704__700.jpg",
        "https://www.boredpanda.com/blog/wp-content/uploads/2021/05/29-609ce906807fd__700.jpg",
        "https://www.boredpanda.com/blog/wp-content/uploads/2021/05/609bd8afc5e45_cgb2ekuw6uy51-png__700.jpg",
        "https://www.boredpanda.com/blog/wp-content/uploads/2021/05/33-609ceb2f2b8ee__700.jpg",
        "https://www.britmums.com/wp-content/uploads/2021/01/homeschool-run-by-alcoholics.jpg.webp",
        "https://static2.srcdn.com/wordpress/wp-content/uploads/2019/06/harry-potter-logic-mems.jpg?q=50&fit=crop&w=740&h=370&dpr=1.5",
        "https://www.scrolldroll.com/wp-content/uploads/2018/06/Engineering-Memes-and-Jokes-14.png",
        "https://www.scrolldroll.com/wp-content/uploads/2018/06/Engineering-Memes-and-Jokes-13.png"]

@app.route('/')
def index():
    url = random.choice(images)
    return render_template('index.html', url=url)

if __name__ == "__main__":
    app.run(host="0.0.0.0")

