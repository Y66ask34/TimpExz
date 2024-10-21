FROM ubuntu

LABEL author=Fakov_Stanislav_231_3210

RUN apt-get update

RUN apt-get install build-essential -y

RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y

WORKDIR /root/

RUN mkdir MyProj_231-3210_Fakov

WORKDIR /root/MyProj_231-3210_Fakov/

COPY *.pro /root/MyProj_231-3210_Fakov/

COPY *.cpp /root/MyProj_231-3210_Fakov/

COPY *.h /root/MyProj_231-3210_Fakov/

COPY *.db /root/MyProj_231-3210_Fakov/


RUN qmake FilmDB_tr.pro

RUN make


ENTRYPOINT ["./FilmDB_tr"]
