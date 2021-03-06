\name{impute}
\alias{impute}

\title{Impute missing genotypes using an snmf object}
\description{
Impute missing genotypes in a genotype file (lfmm) by using ancestry and genotype frequency estimates from an \code{snmf} run. Generate an  \code{lfmm} file. See \code{\link{lfmm}}.
}
\usage{
impute (object, input.file, method, K, run) 
}

\arguments{
\item{object}{
An snmfProject object.
}
\item{input.file}{A path (character string) for an input file with missing genotypes, used previously when generating the snmf object. 
}
\item{method}{A character string: "random" or "mode". With "random", imputation is performed by using the genotype probabilities. With "mode", the most likely genotype is in for matrix completion. 
}
\item{K}{An integer value. The number of ancestral populations.
}

\item{run}{An integer value. A particular run used for imputation (usually the run that minimizes the cross entropy criterion).
}
}
\value{
\item{NULL}{The function writes the imputed genotypes in an output file having the "_imputed.lfmm" suffix.
}
}
\author{
  Olivier Francois
}
\seealso{
\code{\link{lfmm}}
\code{\link{snmf}}
}
\examples{
### Example of analysis ###

data("tutorial")
# creation of a genotype file with missing genotypes
# The data contain 400 SNPs for 50 individuals.

dat = as.numeric(tutorial.R)
dat[sample(1:length(dat), 100)] <-  9
dat <- matrix(dat, nrow = 50, ncol = 400 )
write.lfmm(dat, "genotypes.lfmm")

################
# running snmf #
################

project = snmf("genotypes.lfmm", K = 4, 
        entropy = TRUE, repetitions = 10,
        project = "new")
        
# select the run with the lowest cross-entropy value
best = which.min(cross.entropy(project, K = 4)

# Impute the missing genotypes
impute(project, "genotypes.lfmm", method = 'mode', K = 4, run = best)

# Compare with truth: proportion of correct imputation results
mean( tutorial.R[dat == 9] == read.lfmm("genotypes.lfmm_imputed.lfmm")[dat == 9] )

}


\keyword{snmf}
