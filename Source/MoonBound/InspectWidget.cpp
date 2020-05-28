// Fill out your copyright notice in the Description page of Project Settings.


#include "InspectWidget.h"

void UInspectWidget::ChangeSubtitles()
{
	if (Subtitles.IsValidIndex(CurrSub))
	{
		CurrentText = Subtitles[CurrSub].Text;
		GetWorld()->GetTimerManager().SetTimer(SubtitlesTimer, this, &UInspectWidget::ChangeSubtitles, Subtitles[CurrSub].DisplayTime, false);
		CurrSub++;
	}
}

void UInspectWidget::UpdateSubtitles(TArray<struct FSubtitles> subs)
{
	Subtitles.Empty();
	Subtitles = subs;
}

void UInspectWidget::Open()
{
	CurrSub = 0;
	ChangeSubtitles();
}

void UInspectWidget::Close()
{
	GetWorld()->GetTimerManager().ClearTimer(SubtitlesTimer);
}


