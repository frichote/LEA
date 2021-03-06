\name{as.qmatrix}
\alias{as.qmatrix}
\title{Convert an ancestry matrix into an object of class Qmatrix}
\usage{
as.qmatrix(Q)
}
\arguments{
\item{Q}{an object of class \code{matrix} containing a matrix of ancestry coefficients generated by \code{snmf} or another program.}
}
\value{
An object of class \code{Qmatrix}.
}
\description{
This function tests and converts ancestry \code{matrix} objects.
}
\examples{
library(LEA)
## an example with 3 individuals and 2 clusters
Qmatrix <- matrix(c(0.4,0.6,0.3,0.7, 0.2, 0.8), byrow = TRUE, nrow = 3)
Qmatrix <- as.qmatrix(Qmatrix)
barplot(Qmatrix, space = 0, xlab = "individuals",
        ylab = "Ancestry proportions", main = "Ancestry matrix")
}
\author{
Olivier François
}
\seealso{
\link{barplot.Qmatrix}
}

