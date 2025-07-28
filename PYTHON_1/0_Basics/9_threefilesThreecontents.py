contents = ["HIIIIIII","Abhay","Soni"]

filenames = ["doc.txt","doc1.txt","doc2.txt"]

for content,filename in zip(contents,filenames):
    file = open(f"../files/{filename}",'w')
    file.write(content)
