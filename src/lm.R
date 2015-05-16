#linear regression in R
data1<-read.csv("/Users/dengyan/Desktop/2015 spring/OR 6125/project/train.csv")
data2<-read.csv("/Users/dengyan/Desktop/2015 spring/OR 6125/project/train_DR.csv",header=FALSE)
data = as.data.frame(cbind(data1,data2))
data$Open.Date  = as.Date(data$Open.Date, "%m/%d/%Y")
data$City.Group = as.factor(data$City.Group)
data$Type=as.factor(data$Type)
lm.city=lm(revenue~Open.Date+City.Group+Type+V1+V2+V3,data=data)
summary(lm.city)

plot(lm.city$fit,lm.city$residual)

lm.city=lm(log(revenue)~Open.Date+City.Group+Type+V1+V2+V3,data=data)
summary(lm.city)
plot(lm.city$fit,lm.city$residual)

#####################################################################################################
#close form for linear regression
TP=data$Type
T1=rep(0,length(TP))
T2=rep(0,length(TP))
for (i in 1:length(data$Type)){
  if (TP[i]=="IL") {
    T1[i]=1
  }
  else if (TP[i]=="FC")
  {T2[i]=1}
}

CG=data$City.Group
C=rep(0,length(CG))
for (i in 1:length(data$City.Group)){
  if (CG[i]=="Big Cities") {
    C[i]=0
  }
  else{C[i]=1}
}

lr=function(X,y){
  
     beta=solve(t(X)%*%X, t(X)%*%y)
     return(beta)
}
a=rep(1,length(data$revenue))
X=cbind(a,data$Open.Date,C,T1,T2, data$V1,data$V2, data$V3)
y=log(data$revenue)
lm=lr(X,y)

#####################################################################################################

norm_vec <- function(x) sqrt(sum(x^2))

derivative=function(X,y,beta){
  beta=rep(0,8)
  step=0.00000000001
  a=rep(1000,dim(X)[2])
  x_old=beta
  x_new=beta
  while (norm_vec(a)>=20){
    a=as.numeric(-2*t(X)%*%y+2*t(X)%*%X%*%x_new)
    print(norm_vec(y-X%*%x_new))
    x_old=x_new
    x_new=x_old-step*a
  }
beta=x_new
return(beta)
}

constant=rep(1,length(data$revenue))
X=as.matrix(cbind(constant,data$Open.Date, C, T1, T2, data$V1,data$V2, data$V3))
y=log(data$revenue)

estimate=derivative(X,y,rep(0,8))
lm2=derivative(X,y,rep(0,dim(X)[2]))

