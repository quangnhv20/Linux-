file=open('/home/quang/git_quang/Linux-/data.txt','a+')
file.write("added data\n")
data_ = file.read()
print(data_)
file.close()


