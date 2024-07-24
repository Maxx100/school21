## 1. Создание личного репозитория с нужным .gitignore и простым README.MD
### README
Create new -> New project/repository -> Create project (с галочкой напротив Initialize repository with a README)
![Part1Img1.png](misc/images/Part1Img1.png)
### .GITIGNORE
New file -> .gitignore as filename -> choose template if nessesary -> commit
![Part1Img2.png](misc/images/Part1Img2.png)
![Part1Img3.png](misc/images/Part1Img3.png)
## 2. Создание веток develop и master
Ветка master (main) создается автоматически
Ветку develop можно создать через Branches -> New branch
![Part2Img1.png](misc/images/Part2Img1.png)
## 3. Установка ветки develop по умолчанию
Admin area -> Settings -> Repository
Default branch -> Select you branch as default -> Save changes
## 4. Создание issue на создание текущего мануала
Issues -> List -> New issue
Заполнить поля и создать issue
## 5. Создание ветки по issue
Issues -> Development -> Create a branch ->  Create a branch
## 6. Создание merge request по ветке в develop
Merge request -> New merge request -> Select source and target branches -> Compare branches and continue
![Part6Img1.png](misc/images/Part6Img1.png)
## 7. Комментирование и принятие реквеста
Edit commit message -> Type your comment and press merge
![Part7Img1.png](misc/images/Part7Img1.png)
## 8. Формирование стабильной версии в master с простановкой тега
git tag v1
git log
git checkout v1^ (v1~1)
## 9. Работа с wiki проекта
Settings -> General -> Visibility, project features, permissions -> Enable wiki -> Save changes
Wiki -> Create your first page -> Create page
