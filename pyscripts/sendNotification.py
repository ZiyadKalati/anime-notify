import smtplib
from email.message import EmailMessage
import os

"""
The host email address. You can create a random gmail one, that way you don't have to
change the server info [ie server = smtplib.SMTP("smtp.gmail.com", 587)]
Make sure to allow for less secure apps on the gmail host address
"""
pathToHere = os.path.dirname(os.path.dirname(os.path.realpath(__file__))) + "/assets/"
filePath = pathToHere+"tempData.txt"

# Check if file to read from is empty. If so, then quit
if os.stat(filePath).st_size == 0:
    quit()

sender = # Host email address
password = #Host email password
receiver = #You're email address

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

server.sendmail(sender, receiver, text)
server.quit()

