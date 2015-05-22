data1<-read.csv("train.csv")
data2<-read.csv("train_DR.csv",header=FALSE)
data = as.data.frame(cbind(data1,data2))
data$Open.Date  = as.Date(data$Open.Date, "%m/%d/%Y")
data$City.Group = as.factor(data$City.Group)
data$Type=as.factor(data$Type)
data$revenue=log(data$revenue)

library(nnet)
M=max(data$revenue)
data$revenue=data$revenue/M
data.net = nnet(revenue~Open.Date+City.Group+Type+V1+V2+V3, data = data, size=20)
plot(data.net$residual, ylab="residual for log revenue")