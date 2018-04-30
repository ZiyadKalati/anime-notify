import smtplib
from email.message import EmailMessage
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import os
import re

pathToHere = os.path.dirname(os.path.realpath(__file__))
filePath = pathToHere+"/anime-notify/assets/tempData.txt"

# Check if file to read from is empty. If so, then quit
if os.stat(filePath).st_size == 0:
    quit()

sender = "archamea.history@gmail.com"
receiver = "ziyadmoustafa@hotmail.com"
password = "Adgonoadfy97"
subject = "New Anime"

msg = MIMEMultipart()
msg['From'] = sender
msg['To'] = receiver
msg['Subject'] = subject

with open(filePath) as fp:
    body = fp.read()

body = (re.findall(r"[^|\n]+", body))

htmlbody = []
for i in range(0, len(body), 2):
    htmlbody.append(f"<p><a href=\"{body[i+1]}\">{body[i]}</a></p>")

htmlbody = ''.join(htmlbody)
msg.attach(MIMEText(htmlbody, 'html'))
text = msg.as_string()
server = smtplib.SMTP("smtp.gmail.com", 587)
server.starttls()
server.login(sender, password)

server.set_debuglevel(True)
try:
	server.sendmail(sender, receiver, text)
finally:
	server.quit()
